package tools

import "os"

func InCI() bool {
	return os.Getenv("CI_ENV") == "1"
}
