import junit.framework.TestCase;

import java.util.Random;

public class VerificationTest extends TestCase{

    public VerificationTest(String testName) {
        super(testName);
    }


    public void testManualTest()
    {
        //You can use this function to implement your manual testing
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://www.google.com")); // True
        assertTrue(urlVal.isValid("https://www.bankofamerica.com")); // Returns false but should be true
        assertTrue(urlVal.isValid("ftp://172.16.254.1:8000")); // Returns false but should be true.
    }


    public void testYourFirstPartition()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        // Baseline
        assertTrue(urlVal.isValid("http://www.google.com")); // True
        // Valid URLS - Comment out failed tests.
        assertTrue(urlVal.isValid("http://www.localhost.com:80")); // Valid port number - returns false should be true
        assertTrue(urlVal.isValid("http://www.localhost.com/about")); // Valid extension.
        assertTrue(urlVal.isValid("http://www.localhost.com/about?name=john")); // Valid query string.

        assertTrue(urlVal.isValid("https://www.localhost.com:80")); // Valid port number - returns false should be true
        assertTrue(urlVal.isValid("https://www.localhost.com/about")); // Valid extension - returns false should be true
        assertTrue(urlVal.isValid("https://www.localhost.com/about?name=john")); // Valid query string - returns false should be true.

        assertTrue(urlVal.isValid("ftp://www.filezilla.com"));
    }

    public void testYourSecondPartition(){
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://www.google.com")); // True
        // Null URL
        assertFalse(urlVal.isValid(null));
        // Invalid Scheme
        assertFalse(urlVal.isValid("http/www.localhost.com"));
        assertFalse(urlVal.isValid("http//www.localhost.com"));
        assertFalse(urlVal.isValid("http:www.localhost.com"));
        assertTrue(urlVal.isValid("http://www.localhost.com"));
        assertFalse(urlVal.isValid("https/www.localhost.com"));
        assertFalse(urlVal.isValid("https//www.localhost.com"));
        assertFalse(urlVal.isValid("https:www.localhost.com"));
        assertTrue(urlVal.isValid("https://www.localhost.com"));
        // Invalid authority
        assertFalse(urlVal.isValid("http://www.localhost.1aa"));
        assertFalse(urlVal.isValid("http://"));
        assertFalse(urlVal.isValid("https://www.localhost.1aa"));
        assertFalse(urlVal.isValid("https://"));
        // Invalid port
        assertFalse(urlVal.isValid("http://www.localhost.com:-256"));
        assertFalse(urlVal.isValid("http://www.localhost.com:1233456789"));
        assertFalse(urlVal.isValid("http://www.localhost.com:aa"));
        assertTrue(urlVal.isValid("http://www.localhost.com:8000"));
        // invalid path
        assertFalse(urlVal.isValid("http://www.localhost.com/.."));
        assertFalse(urlVal.isValid("http://www.localhost.com/../"));
        assertFalse(urlVal.isValid("http://www.localhost.com/..//sample.txt"));
        // invalid combinations
        assertFalse(urlVal.isValid("http:/www.localhost.com:1234"));
        assertFalse(urlVal.isValid("http/www.localhost.com/assert"));
        assertTrue(urlVal.isValid("https://www.localhost.com/assert?name=john"));
    }

    public void testIsValid()
    {
        // {scheme} + {site} + {path-optional} + {port-optional}
        // Valid and Invalid Scheme
        String[] validScheme = {"http://", "ftp://", "https://", "", "h3t://"};
        String[] invalidScheme = {"h3t://", "http:/", "http:", "http/", "://"};
        // Valid and Invalid Site
        String[] validSite = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com"};
        String[] invalidSite = {"256.256.256.256", "1.2.3.4.5", "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.a1a", "go.1aa", "aaa.", ".aaa", "aaa", ""};
        // Valid and Invalid Port
        String[] validPort = {":80", ":65535", ":0", ""};
        String[] invalidPort = {":-1", ":65636", ":65a"};
        // Valid and Invalid Path
        String[] validPath = {"/test1", "/t123", "/$23", "/test1/", "", "/test1/file"};
        String[] invalidPath = {"/..", "/../", "/..//file", "/test1//file"};

        Random random = new Random();
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        Integer passedTests = 0;
        Integer failedTests = 0;

        // Valid URL
        for (int i = 0; i < 100 ; i++) {
            Integer validSchemeInt = random.nextInt(validScheme.length);
            Integer validSiteInt = random.nextInt(validSite.length);
            Integer validPortInt = random.nextInt(validPort.length);
            Integer validPathInt = random.nextInt(validPath.length);

            String validURL = validScheme[validSchemeInt] + validSite[validSiteInt] + validPort[validPortInt] + validPath[validPathInt];
            Boolean isURLValid = urlVal.isValid(validURL);
            if (isURLValid) {
                passedTests++;
            }
            else {
                failedTests++;
            }
        }

        // Invalid URL
        for (int i = 0; i < 100 ; i++) {
            Integer invalidSchemeInt = random.nextInt(invalidScheme.length);
            Integer invalidSiteInt = random.nextInt(invalidSite.length);
            Integer invalidPortInt = random.nextInt(invalidPort.length);
            Integer invalidPathInt = random.nextInt(invalidPath.length);

            String invalidURL = invalidScheme[invalidSchemeInt] + invalidSite[invalidSiteInt] + invalidPort[invalidPortInt] + invalidPath[invalidPathInt];
            Boolean isURLValid = urlVal.isValid(invalidURL);
            if (!isURLValid) {
                passedTests++;
            }
            else {
                failedTests++;
            }
        }

        System.out.println("Passed Tests: " + passedTests);
        System.out.println("Failed Tests: " + failedTests);
    }
}


