# Luhn_algorithm_checksum  

## Usage  
Algorithm was created in the 60's. It has been widely used for example  
verifying credit card and SSN validity.  
  
## Program  
User can:  
    1) insert a number sequence  
    2) select a premade number sequence  
By replicating Luhn algorithm, the Checksum of the sequence is calculated.  
  
Algorithm:  
- from the right hand side of the number sequence, every second  
  number is multiplied by 2. For example:  
  12345   ==>>    1 2*2 3 4*2 5  
  6428    ==>>    6*2 4 2*2 8  
- if the product is 2-digit (>=10 and <=18), the two digits are summed.  
  For example: 7113 ==>> 7*2 1 1*2 3 ==>> 14 1 2 3 ==> 1+4 1 2 3==> 5 1 2 3  
- now all the numbers are summed (5 1 2 3 ==>> 11 (=sum))  
- checksum (=9):  
  10 - (sum mod 10) ==>> 10 - (11 mod 10) ==>> 10 - 1 ==>> __9__

https://github.com/Ultsi00/Luhn_algorithm_checksum/assets/60548494/eacb5075-7b51-42fd-ae45-b05c4697a0eb
