

import junit.framework.TestCase;

// This file tests the incorrect URL validator.
// All assertions that have been commented out failed due to a bug.

public class UrlValidatorTest extends TestCase {


    public UrlValidatorTest(String testName) {
        super(testName);
    }


    public void testManualTest()
    {
        //You can use this function to implement your manual testing
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://www.google.com")); // True
//        assertTrue(urlVal.isValid("https://www.bankofamerica.com")); // Returns false but should be true
//        assertTrue(urlVal.isValid("ftp://172.16.254.1:8000")); // Returns false but should be true.
    }


    public void testYourFirstPartition()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        // Baseline
        assertTrue(urlVal.isValid("http://www.google.com")); // True
        // Valid URLS - Comment out failed tests.
//        assertTrue(urlVal.isValid("http://www.localhost.com:80")); // Valid port number - returns false should be true
        assertTrue(urlVal.isValid("http://www.localhost.com/about")); // Valid extension.
        assertTrue(urlVal.isValid("http://www.localhost.com/about?name=john")); // Valid query string.

//        assertTrue(urlVal.isValid("https://www.localhost.com:80")); // Valid port number - returns false should be true
//        assertTrue(urlVal.isValid("https://www.localhost.com/about")); // Valid extension - returns false should be true
//        assertTrue(urlVal.isValid("https://www.localhost.com/about?name=john")); // Valid query string - returns false should be true.

//        assertTrue(urlVal.isValid("ftp://www.filezilla.com"));
    }

    public void testYourSecondPartition()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://www.google.com")); // True
        // Null URL
        assertFalse(urlVal.isValid(null));
        // Invalid Scheme
        assertFalse(urlVal.isValid("http/www.localhost.com"));
        assertFalse(urlVal.isValid("http//www.localhost.com"));
        assertFalse(urlVal.isValid("http:www.localhost.com"));
        assertTrue(urlVal.isValid("http://www.localhost.com"));
//        assertFalse(urlVal.isValid("https/www.localhost.com"));
//        assertFalse(urlVal.isValid("https//www.localhost.com"));
//        assertFalse(urlVal.isValid("https:www.localhost.com"));
//        assertTrue(urlVal.isValid("https://www.localhost.com"));
        // Invalid authority
//        assertFalse(urlVal.isValid("http://www.localhost.1aa"));
//        assertFalse(urlVal.isValid("http://"));
//        assertFalse(urlVal.isValid("https://www.localhost.1aa"));
//        assertFalse(urlVal.isValid("https://"));
        // Invalid port
        assertFalse(urlVal.isValid("http://www.localhost.com:-256"));
        assertFalse(urlVal.isValid("http://www.localhost.com:1233456789"));
        assertFalse(urlVal.isValid("http://www.localhost.com:aa"));
//        assertTrue(urlVal.isValid("http://www.localhost.com:8000"));
        // invalid path
        assertFalse(urlVal.isValid("http://www.localhost.com/.."));
        assertFalse(urlVal.isValid("http://www.localhost.com/../"));
        assertFalse(urlVal.isValid("http://www.localhost.com/..//sample.txt"));
        // invalid combinations
//        assertFalse(urlVal.isValid("http:/www.localhost.com:1234"));
        assertFalse(urlVal.isValid("http/www.localhost.com/assert"));
//        assertTrue(urlVal.isValid("https://www.localhost.com/assert?name=john"));
    }
    //You need to create more test cases for your Partitions if you need to

    public void testIsValid()
    {
        // {scheme} + {site} + {path-optional} + {port-optional}
        // Valid and Invalid Scheme
        String[] validScheme = {"http://", "ftp://", "https://", "", "h3t://"};
        String[] invalidScheme = {"h3t://", "http:/", "http:", "http/", "://"};
        // Valid and Invalid Site
        String[] validSite = {};
        String[] invalidSite = {};
        // Valid and Invalid Port
        String[] validPort = {};
        String[] invalidPort = {};
        // Valid and Invalid Path
        String[] validPath = {};
        String[] invalidPath = {};

    }



}
