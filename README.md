thread-cleanup-demo

This demo shows what happens if threads are not properly cleaned up before exiting the program.

Running it without arguments will properly clean up all threads and the program will exit without issue.

If you run it with '-forgetful' main() will exit before the other threads are resolved and will crash.
