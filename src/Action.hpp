#pragma once

#include <string>

class Action {
private:
    std::string m_name;
    std::string m_type;

public:
    Action(const std::string& name, const std::string& type);

    const std::string& name() const;
    const std::string& type() const;
};
