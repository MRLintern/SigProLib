#include "rms.hpp"

void sig_rms(double *pSig_src_arr, uint32_t blockSize, double * pResult)
{
    double sum =0.0;
    uint32_t blkCnt;
    double in;


    //loop unrolling

    blkCnt = blockSize >>2;

   while(blkCnt >0){

    in = *pSig_src_arr++;
     sum  +=in*in;
    in = *pSig_src_arr++;
     sum  +=in*in;
    in = *pSig_src_arr++;
     sum  +=in*in;
    in = *pSig_src_arr++;
     sum  +=in*in;

     blkCnt--;
   }
   blkCnt = blockSize %0x4;

   while(blkCnt >0){
     in = *pSig_src_arr++;
     sum  +=in*in;
     blkCnt--;
   }

   *pResult =sqrt(sum/(double)blockSize);
}
