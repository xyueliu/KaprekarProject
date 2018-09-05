  #include<stdio.h>
  #include<stdlib.h>
  #include<math.h>
  #include "kaprekarUtils.h"
/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers 
 * whose sum is equal to the original number.  For the purposes of 
 * this method, we restrict our consideration to base-10 representations.</p>
 * 
 * For example, 45 is a Kaprekar number, because 
 *   45<sup>2</sup> = 2025 
 * and 
 *   20 + 25 = 45. 
 * 
 * <p>See Wikipedia's  
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 * 
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number, 
 * <code>false</code> otherwise.
 */

int isKaprekar (int n){
	
  if(n < 1) {
    return 0;
  }

  int i;
  long square, first, second, numberOfDigits;
  long modulus = 1;
  
  square = (long)n * (long)n;
  numberOfDigits = log10(square) + 1;
  i=1;
  //for each possible "split" of the square...
  while(i<=numberOfDigits) {
	i++;
    //increase the modulus by a factor of 10
    modulus *= 10;

    //split the square into two parts
    first = square / modulus;
	second = square - (modulus * first);
	if(second > 0 && second < modulus && first + second == n) {
       return (1);
	}
	for(first = square / modulus; first % 10 == 0 && first > 10; first = first / 10){
		
		if ((first % 10) != 0){
			break;
		}
	}
    //test if the split makes a Kaprekar number 	  
	  if(second > 0 && second < modulus && first + second == n) {
       return (1);
	  }
  }
  return 0;
}
