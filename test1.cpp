#include <CkCrypt2.h>
#include <CkStringBuilder.h>

void ChilkatSample(void)
    {
    // This example requires the Chilkat API to have been previously unlocked.
    // See Global Unlock Sample for sample code.
    // 
    CkCrypt2 crypt;

    // Base32 secret key:
    const char *secretKey = "oebf ytfl qmzb p4xd 2ztf zyz4 hjrw 3uyo";

    CkStringBuilder sbKey;
    bool success = sbKey.Append(secretKey);

    // Remove SPACE chars.
    int numRemoved = sbKey.Replace(" ","");

    // Note: A new token is generated every 30 seconds.  You must generate within the same 30 second interval to get the same result.

    // Generate 6 digits.
    int numDigits = 6;
    // 30 second time period.
    int timePeriod = 30;
    std::cout << "Your token is: " << crypt.totp(sbKey.getAsString(),"base32","0","",timePeriod,numDigits,-1,"sha1") << "\r\n";
    }