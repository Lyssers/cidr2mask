# CIDR 2 MASK
Converts a CIDR range into a subnet mask e.g. from 24 to 255.255.255.0

### Usage:

1. Compile with GCC like:

`gcc cidr2mask.c -o cidr2mask.o`

Run like:

`./cidr2mask.o 24`

Output:

```
Binary Subnet Mask: 11111111111111111111111100000000
Decimal Subnet Mask: 4294967040
Subnet Mask in Dotquad: 255.255.255.0
```

