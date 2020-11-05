while(i < midt - start + 1 && j < slut - midt){
        if(L1[i] <= L2[j]){
            L[start + i + j] = L1[i];
            i++;
        }
        else{
            L[start + i + j] = L2[j];
            j++;
        }
    }
    if(i == midt - start + 1){
        for(k = j; k < slut - midt - 1; k++)
            L[start + i + k] = L2[k];
    }    
    else {
        for(k = i; k < midt - start; k++){
            L[start + j + k] = L1[k];
        }