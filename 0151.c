char * reverseWords(char * s){
    
  char reversed[10000] = "";
  // memset(reversed, '\0', sizeof(reversed));
  char *token = strtok (s," ");
  char temp[10000];
  bool first = true;

  while(token != NULL) {
      
      strcpy(temp, token);
      
      if(!first) {
         strcat(temp, " "); 
      }
      
      first = false;
      
      strcat(temp, reversed);
      strcpy(reversed, temp);
      
      token = strtok (NULL, " ");
      
  }
  
  char *reversedWord = malloc(sizeof(char)*strlen(reversed)+1);
  strcpy(reversedWord, reversed);
  
  return reversedWord;
}