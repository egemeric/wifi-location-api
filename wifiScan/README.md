this program scans the wifi networks and logs with their GPS locations(under development)  
 

## Development files for libmnl (fedora)

```
yum install libmnl.x86_64 libmnl-devel.x86_64  
```

## Development files for libmnl (debian or ubuntu)

```
apt-get install libmnl0 libmnl-dev
```

## Usage
### Compaile 
```
make clean
make
```
You may have use 'sudo' with

```
./bin/wifiScan wlp0s20u8
```
