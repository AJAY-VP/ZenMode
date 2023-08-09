#pragma once
class OperatingSystemAction {
public:
    virtual ~OperatingSystemAction() {}
    virtual void execute() = 0;
};