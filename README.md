# PROJECT 'LIBRARY'

## Description
The "main" program performs simple arithmetic calculations and text preprocessing. User has to choose desired library and then choose an action (among available) and follow program instructions after that. There are two libraries: math and text.

Math library provide such actions for now:

| Action | Description             |
| ------ | ----------------------- |
| \+     | add  A with B           |
| \-     | substract B from A      |
| \*     | multiply A by B         |
|  /     | divide A by B           |
|  !     | get factorial of A      |
|  r     | get square root of A    |
|  x     | exit                    |

Text library prWq
| Action | Description               |
| ------ | ------------------------- |
|  u     | change text to upper case |
|  l     | change text to lower case |
|  x     | exit                      |


## How to install
After you get the sources on your machine, you may compile this program on your system. Follow instructions below.

#### Step 1. Get into the project directory:
```
cd project
```
#### Step 2. Run make to build your program (with sudo):
```
sudo make
```
#### Step 3. Use program:
```
./main
```
#### Step 4. After all, in case you need to uninstall this program, run the command:
```
sudo make clean
```

> [!IMPORTANT]
> Steps 2 and 4 work with ```/usr/lib```. So they should run under the root privileges (e.g. with ```sudo```).

## For maintainers
When making changes in the project, do not forget to update the README.md.

## Out contacts
In case of emergency you may contact us via:
> E-mail: echo@laptop.com
