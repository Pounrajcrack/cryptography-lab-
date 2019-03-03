#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    int i,j,m=0,n=0,l,k,a[16]={0},b[16]={0},c[6][6]={0},f[6][6]={0};
    char text[100],am[6][6]={0},key[20]={0},km[6][6]={0},x[6][6]={0};
    unsigned char sbox[16][16]={0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67,
            0x2b, 0xfe, 0xd7, 0xab, 0x76, 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59,
            0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 0xb7,
            0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1,
            0x71, 0xd8, 0x31, 0x15, 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05,
            0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, 0x09, 0x83,
            0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29,
            0xe3, 0x2f, 0x84, 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
            0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, 0xd0, 0xef, 0xaa,
            0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c,
            0x9f, 0xa8, 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc,
            0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, 0xcd, 0x0c, 0x13, 0xec,
            0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19,
            0x73, 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee,
            0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, 0xe0, 0x32, 0x3a, 0x0a, 0x49,
            0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
            0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4,
            0xea, 0x65, 0x7a, 0xae, 0x08, 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6,
            0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, 0x70,
            0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9,
            0x86, 0xc1, 0x1d, 0x9e, 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e,
            0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, 0x8c, 0xa1,
            0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0,
                0x54, 0xbb, 0x16};
    char mc[4][4]={0x02,0x03,0x01,0x01,0x01,0x02,0x03,0x01,0x01,0x01,0x02,0x03,0x03,0x01,0x01,0x02};
    double time;
    printf("enter the plain text:");
    gets(text);
    printf("enter the key : ");
    gets(key);
    l=strlen(text);
    k=strlen(key);
   //text ascii
    for(i=0;i<l;i++)
    {
       a[i]=text[i];
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            am[j][i]=a[m];
            m++;
        }
    }
   //key ascii
    for(i=0;i<k;i++)
    {
        b[i]=key[i];
    }
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            km[j][i]=b[n];
            n++;
        }
    }
    //add round key
    clock_t begin1=clock();
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            x[i][j]=(am[i][j])^(km[i][j]);
        }
    }
    clock_t end1=clock();
    time=(double)((end1-begin1)*1000000000)/CLOCKS_PER_SEC;
    printf("result of add round key is \n");
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("  %02X",x[i][j]);
        }
        printf("\n");
    }
    printf("\n time taken is %lfclocks/ns \n",time);
    //sbox substitution
    int r,t,sb[5][5];
    clock_t begin3=clock();
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            r=x[i][j]/16;
            t=x[i][j]%16;
            sb[i][j]=sbox[r][t];
        }
    }
    clock_t end3=clock();
    time=(double)((end3-begin3)*1000000000)/CLOCKS_PER_SEC;
    printf("\n sbox substitution is :\n");
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("  %02X",sb[i][j]);
        }
        printf("\n");
    }
    printf("\n time for substution is  %fclocks/ns \n",time);
    //raw shifting
     clock_t begin2=clock();
     k=0;
     for(i=0;i<4;i++)
        {
        c[k][i]=sb[k][i];
        }
        k++;
    if(k=1)
    {
        for(j=0,i=1;i<4;i++,j++)
        {
            c[k][j]=sb[k][i];
        }
        if(i=4)
        {
            i=0;
            c[k][j]=sb[k][i];
        }
        k++;
    }
    if(k=2)
    {
        for(j=0,i=2;i<4;i++,j++)
        {
            c[k][j]=sb[k][i];
        }
         for(j=2,i=0;j<4;i++,j++)
        {
            c[k][j]=sb[k][i];
        }
    }
     if(k=3)
    {
        for(j=0,i=3;i<4;j++,i++)
        {
            c[k][j]=sb[k][i];
        }
         for(j=1,i=0;j<4;i++,j++)
        {
            c[k][j]=sb[k][i];
        }
    }
    clock_t end2=clock();
        printf("\n after row left shifting \n");
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
         printf(" %02X ",c[i][j]);
        }
        printf("\n");
    }
    time=(double)((end2-begin2)*1000000000)/CLOCKS_PER_SEC;
    printf("\n time for shifting is  %fclocks/ns \n",time);
    int  bm[6][6]={0},nc[6][6]={0},z[6]={0};
    char p;
   //mix column
   printf("after mix column : \n");
    clock_t begin4=clock();
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                if(mc[i][k]==0x01)
                {
                    z[k]=c[k][j];
                }
                if(mc[i][k]==0x02)  
                {
                    z[k]=c[k][j]<<0x1;
                }
                if(mc[i][k]==0x03)
                {
                    p=c[k][j];
                   z[k]=(c[k][j]<<0x1)^p;
                }
               /* if(z[k]>0xff)
                {
                    z[k]=z[k]^0x1b;
                }*/
            }
            bm[i][j]=z[0]^z[1]^z[2]^z[3];
        }
    }
    clock_t end4=clock();    
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
         printf(" %02X ",bm[i][j]&0xff);
        }
        printf("\n");
    }
    
    time=(double)((end4-begin4)*1000000000)/CLOCKS_PER_SEC;
    printf("\n time for mix column is  %f clocks/ns\n",time);
    return 0;
}


