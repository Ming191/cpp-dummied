
#ifndef _SLOWURL_H_

#define _SLOWURL_H_



#include <string>



namespace slowhttptest {



class Url {

 public:

  Url();

  bool prepare(const char* url);



  const int isSSL() const {

    return is_ssl_;

  }

  const int isLiteralIPv6() const {

    return is_literal_ipv6_;

  }

  const std::string& getHost() const {

    return host_;

  }

  const int getPort() const {

    return port_;

  }

  const char* getPortStr() const {

    return port_str_.c_str();

  }

  const std::string& getPath() const {

    return path_;

  }

  const char* getData() const {

    return data_.c_str();

  }



  const size_t getPathLen() const {

    return path_.size();

  }



 private:

  std::string data_;

  std::string host_;

  std::string path_;

  std::string port_str_;

  int port_;

  bool is_ssl_;

  bool is_literal_ipv6_;

};



class Proxy {

 public:

  Proxy();

  bool prepare(const char* proxy);

  const std::string& getHost() const {

    return host_;

  }

  const int getPort() const {

    return port_;

  }

  const char* getPortStr() const {

    return port_str_.c_str();

  }

  const char* getData() const {

    return data_.c_str();

  }



private:

  std::string data_;

  std::string host_;

  std::string port_str_;

  int port_;

 

};



} // namespace slowhttptest



#endif

