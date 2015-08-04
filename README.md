# jailstat 
Type-aware jailstat(1) implementation for the FreeBSD operating system.

## About
`jailstat` extracts and displays detailed information about system jails from a
live kernel or a kernel core dump from an arbitrary architecture.

Any target must have an available CTF data set. By using the type-aware KVM
library [libtak](https://github.com/lovasko/libtak), `jailstat` maps the symbol
`allprison` to its [internal query structures](https://github.com/lovasko/jailstat/blob/master/src/types.h) that
are later processed by the table layout engine
[libtabl](https://github.com/lovasko/libtabl). 

This software is part of the Google Summer of Code 2015. The FreeBSD Project,
and namely John-Mark Gurney, mentored and supervised the creation of this
software.

## Build & run
```
$ ninja
$ ctfconvert -L jsl bin/jailstat
$ sudo ./bin/jailstat
```

## Dependencies
 * [libtak](https://github.com/lovasko/libtak)
 * [libtabl](https://github.com/lovasko/libtabl)
 * [libits](https://github.com/lovasko/libits)
 * [m_list](https://github.com/lovasko/m_list)

## License
2-clause BSD license. For more information please consult the
[LICENSE](LICENSE.md) file. In the case that you need a different license, feel
free to contact me.

## Author
Daniel Lovasko lovasko@freebsd.org

