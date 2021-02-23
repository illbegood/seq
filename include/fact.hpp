#ifndef F3025756_6FAE_499D_BAD0_3EA12E4A9295
#define F3025756_6FAE_499D_BAD0_3EA12E4A9295

#include <string>

struct Fact{
    struct hash
    {
      std::size_t operator()(const Fact& f) const
      {
        return std::hash<std::string>()(f.value);
      }
    };

    Fact() {}

    ~Fact() {}

    Fact(const std::string& s) : value(s) {}

    bool operator==(const Fact & other) const;

    bool operator!=(const Fact & other) const;

    const std::string& getValue() const;
private:
    const std::string value;
};


#endif /* F3025756_6FAE_499D_BAD0_3EA12E4A9295 */
