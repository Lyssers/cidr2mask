# CIDR 2 MASK
Converts a CIDR range into a subnet mask e.g. from 24 to 255.255.255.0

Useful for some tools that may only accept one or another

### Usage:

1. Compile with GCC like:

`gcc cidr2mask.c -o cidr2mask.o`

2. Run like:

`./cidr2mask.o 24`

3. Output:

```
Binary Subnet Mask: 11111111111111111111111100000000
Decimal Subnet Mask: 4294967040
Subnet Mask in Dotquad: 255.255.255.0
```
(Optional) `sudo cp ./cidr2mask.o /usr/bin/cidr2mask` to run it using just `cidr2mask`

The output is very verbose by default, if you'd like a less verbose mode open an issue and I can do it!

Or alternatively use awk, xargs and tail, e.g.:

```
 ./cidr2mask.o 24 | tail -1 |  awk -F ': ' '{print $2}') >> somefile
```
or e.g. use it with [subnetter](https://github.com/Lyssers/subnetter)
```
 echo $(ifconfig wlan0 | grep 'inet' | head -1 | awk -F ' ' '{print $2}')  $(cidr2mask 24 | tail -1 |  awk -F ': ' '{print $2}') | xargs subnetter 
```
