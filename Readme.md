# Buffer Overflows
Buffer overflows continue to be one of the most common security vulnerabilities in current software and are usually the result of incorrectly constructed programs. Buffer overflows occur when too small memory areas are reserved for a given amount of data, which usually overwrites adjacent areas of the memory, which can also contain sensitive data, among other things.
Sensitive data is information for controlling the program flow or the process memory, but also pointers.
Buffer overflows are critical vulnerabilities in software because attackers can often manipulate sensitive data in such a way that infected malware can be successfully executed on the target system.
Most of today's computer systems are based on the Von-Neumann architecture. With such systems, data and programs are stored in the same memory, making it easy for attackers to exploit buffer overflow vulnerabilities. However, the weak points in themselves only arise through negligent programming, the exploitation of which is merely fostered by the von Neumann architecture. In many programming languages, such as C / C++, the check for memory overflows is usually left to the programmer, who often forgets it completely or implements it incorrectly.   
Buffer overflows in JAVA are practically impossible, since the programs run in a runtime that detects and prevents memory area overflows. Also, interpreted programming languages are rarely affected.

[Read more in this blog post](https://markusthill.github.io/buffer-overflows/)
