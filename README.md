# hotrace
[![Build Status](https://travis-ci.org/p-milan/hotrace.svg?branch=master)](https://travis-ci.org/p-milan/hotrace)

## What is hotrace ?


hotrace is a very quick search engine based on association key-value.


### • To start with:

   - hotrace reads the standard input

   - each line contains a key, the next line its value

   - then each line contains a key


• The goal is to find the value of each of these keys as fast as possible (if there is no match we output "key: Not found."

## How does it work ?

We run a hash algorithm on the key word and get a ```number```, then we stock the couple key-value in a binary tree, and stock a pointer to this tree in an array of pointers at the rank ```number```



## How to run the project ?

```sh
git clone https://github.com/p-milan/hotrace
```
## Then run this test :
```
make && ./hotmouli hotrace resources/test01.htr
```
Possible outcome :
```
Running tests...done.
Hotrace : starting control procedure
Control ok.
Speed reference number is 1.39
Less is best.
```
## Or to visualize directly the result :
```
make && ./hotrace < resources/test02.htr
```
Possible outcome :
```
trois: Not found.
```

### Or :
```
make exec
```
Possible outcome :
```
1
2
5
7
9
10
```
