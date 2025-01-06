// You are given a number N. Find the total number of setbits in the numbers from 1 to N.

// Agar koi number n, even hai to n/2  me v same number of set bit honge 
// e.g. n = 12 , set bits in 12(1100) is 2 and set bit in 6(0110) is also 2
// But ye baat kaise prove kre ki agar n even h to n and n/2 me same number of set bit honge
// Agar aap dhyan de to paenge ki even number me right most bit always 0 hoti h and n/2 means hm n ko ek baar right shift kr rhe it means koi set bit ka loss nhi ho rha that why total number of set bits will remains same
// Similarly agar n, odd h to total number of set bit in n, will be equal to set bit in n/2 + 1
// Kuki odd number ka rightmost bit 1(set) hota h aur jb hm n ko 2 se divide krenge to due to right shift ek set bit kho denge, that's why setBit(n) == setBit(n/2) + 1 (for odd numbers)

long long countBits(long long N) {
    
         // Create a vector to store the number of bits in the binary representation of each number.
            vector<int>temp(N+1 , 0);       
         // Initialize a variable to store the final result
            long long cnt = 0;   
        // Compute the number of bits in the binary representation of each number and store the result in temp.
            for(long long i = 1 ; i <= N ; i++)
            {
                 // If i is even, its number of bits is the same as its right-shifted value.
                if(i % 2 == 0)
                {
                    temp[i] = temp[i/2];
                }
                else
                {
                    // If i is odd, its number of bits is one more than its right-shifted value.
                    temp[i] = temp[i/2] + 1;
                }        
                // Add the number of bits in the binary representation of i to the final result.
                cnt += temp[i];
            }     
            return cnt;
    }

// Time Complexity : O(N) , N = size of given number

// Space Complexity : O(N) 
