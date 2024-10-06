int makeBeautiful(string str) {
	int n = str.length();
    
   
    int changesForPattern1 = 0; 
    int changesForPattern2 = 0; 
    
    for (int i = 0; i < n; i++) {
       
        if (i % 2 == 0) {
            if (str[i] != '0') changesForPattern1++;  
            if (str[i] != '1') changesForPattern2++;  
        } else {
            if (str[i] != '1') changesForPattern1++; 
            if (str[i] != '0') changesForPattern2++;  
        }
    }

    return min(changesForPattern1, changesForPattern2);
}