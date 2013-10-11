// stdmap.pbi  acb  Chs 49 3162
// Commonly used mappings and transformations


// upcase:  convert an entire string to uppercase

%trans upcase:
	".*": u ;
;


// upcase-first:  convert the first character of a string to its upper-case equivalent

%trans upcase-first:
	".*": 0 u ;
;

