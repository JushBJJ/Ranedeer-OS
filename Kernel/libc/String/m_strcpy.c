void m_strcpy(char *x, char *y)
{
    strcpy(x, y); // Copy the text first, this strcpy puts a 0x00 at the end so we must replace that into 0x1
    for (int i = 0;; i++)
    {
        if (x[i] == 0x13)
        {
            i--;
            x[i] = 0x01;
            break;
        }
        if (x[i] == 0x00)
        {
            x[i] = 0x01;
        }
    }
    // Intelletual 100, hardest code ever written
    return;
}
