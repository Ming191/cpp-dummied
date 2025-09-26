#pragma once
#include <type_traits>

#include <windows.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <functional>

// Dummy for nlohmann::json
namespace nlohmann {
    class json {
    public:
        class exception : public std::exception {
        public:
            const char* what() const noexcept override {
                return "nlohmann::json::exception";
            }
        };
        
        json() = default;
        json(const json&) = default;
        json& operator=(const json&) = default;
        
        // Constructor with initializer list for objects
        json(std::initializer_list<std::pair<std::string, json>> init) {
            // Dummy implementation
        }
        
        // Constructor with nested initializer list for arrays
        template<typename T>
        json(std::initializer_list<T> init) {
            // Dummy implementation
        }
        
        // Constructor with mixed initializer list (for complex nested structures)
        template<typename... Args>
        json(Args&&... args) {
            // Dummy implementation - accepts any arguments
        }
        
        // Constructor from string literal
        json(const char* value) {
            // Dummy implementation
        }
        
        // Constructor from string
        json(const std::string& value) {
            // Dummy implementation
        }
        
        // Constructor from integer
        json(int value) {
            // Dummy implementation
        }
        
        // Constructor from INT64
        json(INT64 value) {
            // Dummy implementation
        }
        
        // Constructor from UINT64
        json(UINT64 value) {
            // Dummy implementation
        }
        
        // Constructor from DWORD
        json(DWORD value) {
            // Dummy implementation
        }
        
        // Constructor from double
        json(double value) {
            // Dummy implementation
        }
        
        // Constructor from boolean
        json(bool value) {
            // Dummy implementation
        }
        
        // Parse function
        static json parse(const char* first, const char* last, 
                         void* = nullptr, bool = true) {
            return json();
        }
        
        // Check if parsing failed
        bool is_discarded() const { return false; }
        
        // Dump to string
        std::string dump(int indent = -1) const { return "{}"; }
        
        // Array access
        json& operator[](const std::string& key) {
            static json dummy;
            return dummy;
        }
        
        json& operator[](const char* key) {
            static json dummy;
            return dummy;
        }
        
        json& operator[](size_t index) {
            static json dummy;
            return dummy;
        }
        
        // Assignment operators
        json& operator=(const std::string& value) { return *this; }
        json& operator=(const char* value) { return *this; }
        json& operator=(int value) { return *this; }
        json& operator=(INT64 value) { return *this; }
        json& operator=(UINT64 value) { return *this; }
        json& operator=(DWORD value) { return *this; }
        json& operator=(double value) { return *this; }
        json& operator=(bool value) { return *this; }
        
        // Get functions - these are the missing methods causing errors
        template<typename T>
        T get() const {
            if (std::is_same<T, int>::value) {
                return 0;
            } else if (std::is_same<T, INT64>::value) {
                return 0LL;
            } else if (std::is_same<T, UINT64>::value) {
                return 0ULL;
            } else if (std::is_same<T, std::string>::value) {
                return 0;
            } else if (std::is_same<T, double>::value) {
                return 0;
            } else if (std::is_same<T, bool>::value) {
                return 0;
            } else {
                return T();
            }
        }

        // Array operations
        void push_back(const json& value) {}
        
        // Static array creator
        static json array() { return json(); }
        
        // Iterator support (basic)
        json* begin() { return this; }
        json* end() { return this; }
        const json* begin() const { return this; }
        const json* end() const { return this; }
        
        // Size function
        size_t size() const { return 0; }
        
        // Empty check
        bool empty() const { return true; }
    };
}

// Dummy for spdlog
namespace spdlog {
    // Log levels
    enum class level {
        trace = 0,
        debug = 1,
        info = 2,
        warn = 3,
        err = 4,
        critical = 5,
        off = 6
    };
    
    // Level enum typedef for compatibility
    using level_enum = level;
    
    // Sink interface
    class sink {
    public:
        virtual ~sink() = default;
        virtual void log(level lvl, const std::string& msg) {}
        virtual void flush() {}
    };
    
    // File sink
    class file_sink : public sink {
    public:
        file_sink(const std::string& filename) {}
        void log(level lvl, const std::string& msg) override {}
        void flush() override {}
    };
    
    // Daily file sink
    class daily_file_sink : public sink {
    public:
        daily_file_sink(const std::string& filename, int hour = 0, int minute = 0) {}
        void log(level lvl, const std::string& msg) override {}
        void flush() override {}
    };
    
    // Logger class
    class logger {
    public:
        logger(const std::string& name) : name_(name) {}
        
        template<typename... Args>
        void info(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "INFO: " << fmt << std::endl;
        }
        
        template<typename... Args>
        void error(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "ERROR: " << fmt << std::endl;
        }
        
        template<typename... Args>
        void warn(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "WARN: " << fmt << std::endl;
        }
        
        template<typename... Args>
        void debug(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "DEBUG: " << fmt << std::endl;
        }
        
        template<typename... Args>
        void trace(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "TRACE: " << fmt << std::endl;
        }
        
        template<typename... Args>
        void critical(const char* fmt, Args&&... args) {
            // Do nothing or print to console if needed
            // std::cout << "CRITICAL: " << fmt << std::endl;
        }
        
        void set_level(level lvl) {}
        void flush() {}
        
        const std::string& name() const { return name_; }
        
    private:
        std::string name_;
    };
    
    // Global functions
    template<typename... Args>
    void info(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "INFO: " << fmt << std::endl;
    }
    
    template<typename... Args>
    void error(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "ERROR: " << fmt << std::endl;
    }
    
    template<typename... Args>
    void warn(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "WARN: " << fmt << std::endl;
    }
    
    template<typename... Args>
    void debug(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "DEBUG: " << fmt << std::endl;
    }
    
    template<typename... Args>
    void trace(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "TRACE: " << fmt << std::endl;
    }
    
    template<typename... Args>
    void critical(const char* fmt, Args&&... args) {
        // Do nothing or print to console if needed
        // std::cout << "CRITICAL: " << fmt << std::endl;
    }
    
    // Logger creation functions
    inline std::shared_ptr<logger> daily_logger_mt(const std::string& logger_name, 
                                                   const std::string& filename, 
                                                   int hour = 0, int minute = 0) {
        return std::make_shared<logger>(logger_name);
    }
    
    inline std::shared_ptr<logger> rotating_logger_mt(const std::string& logger_name,
                                                      const std::string& filename,
                                                      size_t max_file_size,
                                                      size_t max_files) {
        return std::make_shared<logger>(logger_name);
    }
    
    inline std::shared_ptr<logger> basic_logger_mt(const std::string& logger_name,
                                                   const std::string& filename) {
        return std::make_shared<logger>(logger_name);
    }
    
    inline std::shared_ptr<logger> stdout_logger_mt(const std::string& logger_name) {
        return std::make_shared<logger>(logger_name);
    }
    
    inline std::shared_ptr<logger> stderr_logger_mt(const std::string& logger_name) {
        return std::make_shared<logger>(logger_name);
    }
    
    // Global logger functions
    inline void set_default_logger(std::shared_ptr<logger> default_logger) {
        // Dummy implementation
    }
    
    inline std::shared_ptr<logger> default_logger() {
        static auto dummy_logger = std::make_shared<logger>("default");
        return dummy_logger;
    }
    
    inline std::shared_ptr<logger> get(const std::string& name) {
        return std::make_shared<logger>(name);
    }
    
    inline void register_logger(std::shared_ptr<logger> logger) {
        // Dummy implementation
    }
    
    inline void drop(const std::string& name) {
        // Dummy implementation
    }
    
    inline void drop_all() {
        // Dummy implementation
    }
    
    // Flush functions
    inline void flush_every(std::chrono::seconds interval) {
        // Dummy implementation
    }
    
    inline void flush_on(level lvl) {
        // Dummy implementation
    }
    
    // Level functions
    inline void set_level(level lvl) {
        // Dummy implementation
    }
    
    inline level get_level() {
        return level::info;
    }
    
    // Pattern functions
    inline void set_pattern(const std::string& pattern) {
        // Dummy implementation
    }
    
    // Shutdown function
    inline void shutdown() {
        // Dummy implementation
    }
    
    // Apply function for all loggers
    inline void apply_all(std::function<void(std::shared_ptr<logger>)> fun) {
        // Dummy implementation
    }
}

// SPDLOG_INFO macro
#define SPDLOG_INFO(fmt, ...) spdlog::info(fmt, ##__VA_ARGS__)
#define SPDLOG_ERROR(fmt, ...) spdlog::error(fmt, ##__VA_ARGS__)
#define SPDLOG_WARN(fmt, ...) spdlog::warn(fmt, ##__VA_ARGS__)
#define SPDLOG_DEBUG(fmt, ...) spdlog::debug(fmt, ##__VA_ARGS__)
#define SPDLOG_TRACE(fmt, ...) spdlog::trace(fmt, ##__VA_ARGS__)
#define SPDLOG_CRITICAL(fmt, ...) spdlog::critical(fmt, ##__VA_ARGS__)

// MG_INFO macro for mongoose
#define MG_INFO(args) do { } while(0)

// Dummy for Microsoft Detours
#ifndef DETOURS_INCLUDED
#define DETOURS_INCLUDED

#define NO_ERROR 0L

// Detour function declarations with C linkage
extern "C" {
    LONG DetourTransactionBegin();
    LONG DetourUpdateThread(HANDLE hThread);
    LONG DetourAttach(PVOID* ppPointer, PVOID pDetour);
    LONG DetourDetach(PVOID* ppPointer, PVOID pDetour);
    LONG DetourTransactionCommit();
    LONG DetourTransactionAbort();
}

// Dummy implementations (you can provide empty implementations in a .cpp file)
inline LONG DetourTransactionBegin() { return NO_ERROR; }
inline LONG DetourUpdateThread(HANDLE hThread) { return NO_ERROR; }
//inline LONG DetourAttach(PVOID* ppPointer, PVOID pDetour) { return NO_ERROR; }
//inline LONG DetourDetach(PVOID* ppPointer, PVOID pDetour) { return NO_ERROR; }
inline LONG DetourTransactionCommit() { return NO_ERROR; }
inline LONG DetourTransactionAbort() { return NO_ERROR; }

#endif // DETOURS_INCLUDED

// Dummy mongoose structures (only if not already defined)
#ifndef MONGOOSE_DEFS_INCLUDED
#define MONGOOSE_DEFS_INCLUDED


#define WEBSOCKET_OP_TEXT 1

#endif // MONGOOSE_DEFS_INCLUDED

// Dummy ThreadPool class


// Common namespace - định nghĩa các struct cần thiết

