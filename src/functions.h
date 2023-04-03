#include <stdio.h>
#include <string.h>

unsigned char reset(unsigned char *i, unsigned char *but_tab){
  unsigned char retVal = 0;
  unsigned char size = sizeof(but_tab);
  for (unsigned char j=*i; j<size+1; j++){
    but_tab[j] = HIGH;
  }
  retVal = *i+1;
  return retVal;
}

void check_deactivate(unsigned char *but_tab, unsigned char first_idx, unsigned char last_idx){
  unsigned char tab_idx = 0;
  for (unsigned char i = first_idx; i<=last_idx; i++){
    if (but_tab[tab_idx] == HIGH){
      but_tab[tab_idx] = digitalRead(i);
    } 
    tab_idx++;
  }
}

void cut_text(char** save_mem, const char* text, const unsigned char no_slices){
  unsigned char str_len = strlen(text); 
  unsigned char one_section = str_len/no_slices;
  for (unsigned char i = 0; i<no_slices; i++){
     memcpy(save_mem[i], text+i*one_section, one_section);
  }
}
