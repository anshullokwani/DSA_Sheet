string reverseWord(string str){
    for(int i=0;i<str.size()/2;i++)
    {
        swap(str[i],str[str.size()-1-i]);
    }
    return str;
}