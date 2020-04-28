package Tools

import "os"

func InCI() bool {
	return os.Getenv("CI_ENV") == "1"
}
