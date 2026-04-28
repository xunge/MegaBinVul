#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

namespace PostScript_Support {
    struct Date {
        short year;
        short month;
        short day;
        short hours;
        short minutes;
        short seconds;
        char offsetSign;
        short offsetHour;
        short offsetMin;
        bool containsOffset;
        
        Date(short y, short m, short d, short h, short min, short sec)
            : year(y), month(m), day(d), hours(h), minutes(min), seconds(sec),
              offsetSign('+'), offsetHour(0), offsetMin(0), containsOffset(false) {}
        
        bool operator==(const Date& other) const {
            return year == other.year && month == other.month && day == other.day &&
                   hours == other.hours && minutes == other.minutes && seconds == other.seconds;
        }
    };

    struct DateTimeTokens {
        std::string token;
        char delimiter;
        short noOfDelimiter;
    };

    short GetNumber(const char** str, int digits = 0);
    void tokeniseDateString(const char* inString, std::vector<DateTimeTokens>& tokens);
    void SwapMonthDateIfNeeded(short& day, short& month);
    void AdjustYearIfNeeded(short& year);
    bool IsAlpha(char c);
    bool IsNumeric(char c);
    bool IsLeapYear(short year);
    void constructDateTime(const std::string& token, std::string& dateTimeString);
    std::string ConvertToDate(const char* inString);
}

struct XMP_DateTime {
    // Placeholder for XMP_DateTime structure
};

namespace SXMPUtils {
    void ConvertToDate(const char* dtstr, XMP_DateTime* datetime);
    void ConvertFromDate(const XMP_DateTime& datetime, std::string* dateTimeString);
}