// #ifndef S3FS_ADDHEAD_H_
// #define S3FS_ADDHEAD_H_

// // //#include <memory>
// // //#include <regex.h>
// #include <string>
// // #include <utility>
// #include <vector>

// #include "metaheader.h"
// #include "dummy.h"

// //----------------------------------------------
// // Structure / Typedef
// //----------------------------------------------
// // typedef std::unique_ptr<regex_t, decltype(&regfree)> RegexPtr;

// struct add_header{
//     add_header(RegexPtr pregex, std::string basestring, std::string headkey, std::string headvalue)
//         : pregex(std::move(pregex))
//         , basestring(std::move(basestring))
//         , headkey(std::move(headkey))
//         , headvalue(std::move(headvalue))
//     {}

//     add_header(const add_header&) = delete;
//     add_header(add_header&& val) = default;
//     add_header& operator=(const add_header&) = delete;
//     add_header& operator=(add_header&&) = delete;

//     // RegexPtr      pregex;         // not nullptr means using regex, nullptr means comparing suffix directly.
//     std::string   basestring;
//     std::string   headkey;
//     std::string   headvalue;
// };

// typedef std::vector<add_header> addheadlist_t;

// //----------------------------------------------
// // Class AdditionalHeader
// //----------------------------------------------
// class AdditionalHeader
// {
//     private:
//         static AdditionalHeader singleton;
//         bool                    is_enable;
//         addheadlist_t           addheadlist;

//     protected:
//         AdditionalHeader();
//         ~AdditionalHeader();

//     public:
//         AdditionalHeader(const AdditionalHeader&) = delete;
//         AdditionalHeader(AdditionalHeader&&) = delete;
//         AdditionalHeader& operator=(const AdditionalHeader&) = delete;
//         AdditionalHeader& operator=(AdditionalHeader&&) = delete;

//         // Reference singleton
//         static AdditionalHeader* get() { return &singleton; }

//         bool Load(const char* file);
//         void Unload();

//         bool AddHeader(headers_t& meta, const char* path) const;
//         struct curl_slist* AddHeader(struct curl_slist* list, const char* path) const;
//         bool Dump() const;
// };

// #endif // S3FS_ADDHEAD_H_

// /*
// * Local variables:
// * tab-width: 4
// * c-basic-offset: 4
// * End:
// * vim600: expandtab sw=4 ts=4 fdm=marker
// * vim<600: expandtab sw=4 ts=4
// */
