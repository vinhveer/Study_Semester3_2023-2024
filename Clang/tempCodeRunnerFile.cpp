void DeleteValue(int pos, char str[])
{
    for (int i = pos; i < strlen(str); i++)
        str[i] = str[i+1];
    str[strlen(str)] = '\0';
}