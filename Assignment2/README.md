# Description of each test case

## If you can check if it matches with linux that would be great.

### Most of the cases are POSIX compliant

1. checks if pipe wraps around - if you write to pipe and read out from it you
   should be able to write to it again. (e.g., write 3K, read 3K, write 3K
   again.)  _matches with linux_

2. checks if open behaviour is same as linux.  _matches with linux_

3. Tests pipe - contributed by Snehal Raj.

4. Tests open on creating a file and using it again - contributed by Snehal Raj.
   _interesting test case_ (POSIX compliant).
