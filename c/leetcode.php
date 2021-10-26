#!/usr/bin/env php
<?php

require __DIR__ . '/vendor/autoload.php';

use Inhere\Console\IO\Input;
use Inhere\Console\IO\Output;
use Inhere\Console\Application;
use Inhere\Console\Command;
use Inhere\Console\Controller;

//TODO 使用接口获取信息
/**
 * Class CreateCommand
 * @package app\console\commands
 */
class CreateCommand extends Command
{
    // 命令名称
    protected static $name = 'create';
    // 命令描述
    protected static $description = 'create a new solution';

    /**
     * @usage usage message
     * @arguments 
     *  num     int 编号
     *  url     string leecode 地址
     *  
     * @options 
     *  -o, --opt     some message ...
     *  
     * @param  Inhere\Console\IO\Input $input
     * @param  Inhere\Console\IO\Output $output
     * @return int
     */
    public function execute($input, $output)
    {
        $num = $output->ask("num");
        $url = $output->ask("url");

        if (empty($num) || empty($url)) {
            $output->error("num or url 不能为空", true);
        }

        $_url = parse_url($url, PHP_URL_PATH);
        $arr = array_values(array_filter(explode('/', $_url)));
        $itemName = $arr[1];

        $dir = "src/main/{$num}-{$itemName}";
        $output->info("检查目录 " . __DIR__ . '/' . $dir);
        @mkdir(__DIR__ . '/' . $dir);

        foreach (glob(__DIR__ . '/stubs/*') as $value) {
            $content = file_get_contents($value);

            $content = str_replace('{num}', $num, $content);
            $content = str_replace('{url}', $url, $content);
            $content = str_replace('{task}', str_replace('-', '_', $itemName), $content);

            $name = pathinfo($value, PATHINFO_BASENAME);

            $name = str_replace('{num}', $num, $name);

            $file = __DIR__ . "/$dir/$name";
            file_put_contents($file, $content);
            $output->info("generate {$file}");
        }

        $f = [
            __DIR__ . '/cmake-var/h.txt' => "src/main/{$num}-{$itemName}/{$num}.h",
            __DIR__ . '/cmake-var/c.txt' => "src/main/{$num}-{$itemName}/{$num}.c",
            __DIR__ . '/cmake-var/test.txt' => "src/main/{$num}-{$itemName}/{$num}_test.c",
        ];

        foreach($f as $k => $v) {
            file_put_contents($k, "\n" . $v, FILE_APPEND);
        }

        # trigger CMakeLists.txt
        $content = file_get_contents("CMakeLists.txt");
        $matchAll = [];
        $regex = '/(message\("trigger\sat\s#)(.+)(#"\))/';
        preg_match_all($regex, $content, $matchAll);

        $now = date("Y/m/d H:i:s");
        $content = preg_replace($regex, "$1 {$now} $3", $content);
        file_put_contents("CMakeLists.txt", $content);
    }
}



$app = new Application([
    'name' => 'leetcode helper',
    'version' => '1.0.0',
]);
$app->command(CreateCommand::class);
$app->run();

