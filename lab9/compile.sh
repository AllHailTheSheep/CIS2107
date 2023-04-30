gcc -c *.c
ar rcs libstr2107.a *.o
gcc -o driver.out driver.c -L . -l str2107
./driver.out
# tar cvzf julia-fasick-lab9.tar . 
rm *.o *.a driver.out
