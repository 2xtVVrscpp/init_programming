#include <stdio.h>

#define NETWORK_PART 0xfffff000
#define HOST_PART 0x00000fff

int main(void){
  unsigned char ip_addr[4] = {11, 20, 168, 192};
//  unsigned char ip_addr[4] = {192, 168, 20, 11};
  unsigned char ip_addr_tmp[4];
  int *ip_addr_int;

  printf("ip: %d.%d.%d.%d\n", ip_addr[3], ip_addr[2], ip_addr[1], ip_addr[0]);

  ip_addr_tmp[0] = ip_addr[0];
  ip_addr_tmp[1] = ip_addr[1];
  ip_addr_tmp[2] = ip_addr[2];
  ip_addr_tmp[3] = ip_addr[3];

  ip_addr_int = (int*)ip_addr_tmp;
  printf("ip: %x\n", *ip_addr_int);

  *ip_addr_int = (*ip_addr_int) & NETWORK_PART;
  printf("ip(network): %d.%d.%d.%d\n", ip_addr_tmp[3], ip_addr_tmp[2], ip_addr_tmp[1], ip_addr_tmp[0]);

  ip_addr_int = (int*)ip_addr;
  *ip_addr_int = (*ip_addr_int) & HOST_PART;
  printf("ip(network): %d.%d.%d.%d\n", ip_addr[3], ip_addr[2], ip_addr[1], ip_addr[0]);


  return 0;
}