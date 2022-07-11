# CBFB brainf*ck compiler

Is a compiler which supports both stock [BrainF*ck](https://esolangs.org/wiki/Brainfuck) and [Brainf*ck with Buffer](https://esolangs.org/wiki/Brainfuck$) extension.
It uses C as it's "intermediate representation".

## How to run?

```console
cc cbfb.c -o cbfb     # compile compiler
./cbfb hello.bf       # compile example to C
cc a.c -o hello       # compile resulting C
./hello               # run example
```
