

/*********************************************************/
/* Testing Linker script new section*/
volatile const char specialGLobChar __attribute__ ((section (".mySection"))) = 5;
/*********************************************************/
volatile char globalChar;
const char constGlobalChar = 0xBC;

void func(char * p)
{
    *p = constGlobalChar;
}

int main()
{
    char localChar = 0xCD;
    static const char constLocalChar = 0xDE;
  
    func(&localChar);
    if((localChar == 0xCD) && (constLocalChar == 0xDE))
    {
        globalChar = 0xFF;
    }
    else
    {
        if(constLocalChar == 0xDE)
            localChar = 0xFF;
    }
    return 0;
}
