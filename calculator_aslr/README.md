# Calculator ASLR

The calculator challange with ASLR enabled, you first leak the address of one of the operator and then you use it to calculate address of win_flag and overflow

# To run solution
``python solution.py``

# Compilation

Compiled using Visual Studio 2019, using the following compilation parameters:
* No Code Optimizations
* No Security checks

Linking parameters:
* ``/DYNAMICBASE`` - ASLR
* ``/OPT:NOREF`` - Keep non referenced functions
* ``/LTCG:OFF`` - IDK but it conflicted with the previous one

The source file used for compilation is the calculator_compile.c and not calculator.c
