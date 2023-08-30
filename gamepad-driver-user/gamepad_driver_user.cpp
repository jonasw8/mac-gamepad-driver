//
//  gamepad_driver_user.cpp
//  gamepad-driver-user
//
//  Created by Noah Nübling on 30.08.23.
//


/// Imports from Karabiner VirtualHIDPointing
//#include "version.hpp"
#include <HIDDriverKit/IOHIDDeviceKeys.h>
#include <HIDDriverKit/IOHIDUsageTables.h>

/// Imports from HIDKeyboardDriver sample app
#include <os/log.h>
#include <DriverKit/IOUserServer.h>
#include <DriverKit/IOLib.h>

#include <DriverKit/OSCollections.h>
#include <HIDDriverKit/HIDDriverKit.h>

/// Import Header
#include "gamepad_driver_user.h"


/// --- Lifecycle and iVars ---
/// This is mostly copied from the HIDKeyboardDriver sample project

struct gamepad_driver_user_IVars {
    
    OSArray *elements;
    struct {
        OSArray *elements;
    } keyboard;
};

#define _elements   ivars->elements
#define _keyboard   ivars->keyboard


bool gamepad_driver_user::init() {
    
    /// init
    /// Allocates memory for ivars struct
    /// And assigns allocated memory to inherited `ivars` variable. I think all drivers need to do it like that.
    
    os_log(OS_LOG_DEFAULT, "Groot: Init");
    
    if (!super::init()) {
        return false;
    }
    
    ivars = IONewZero(gamepad_driver_user_IVars, 1);
    if (!ivars) {
        return false;
    }
    
exit:
    return true;
}

void gamepad_driver_user::free() {
    
    /// free
    /// Frees memory of ivars struct
    
    os_log(OS_LOG_DEFAULT, "Groot: Free");
    
    if (ivars) {
        OSSafeReleaseNULL(_elements);
        OSSafeReleaseNULL(_keyboard.elements);
    }
    
    IOSafeDeleteNULL(ivars, gamepad_driver_user_IVars, 1);
    super::free();
}

//kern_return_t IMPL(gamepad_driver_user, Start) {
//    
//    /// Declare vars
//    kern_return_t ret;
//    
//    /// Call super
//    ret = Start(provider, SUPERDISPATCH);
//    if (ret != kIOReturnSuccess) goto fail;
//    
//    /// Register self with system
//    ret = RegisterService();
//    if (ret != kIOReturnSuccess) goto fail;
//    
//    /// Validate
//    assert(ret == kIOReturnSuccess);
//    
//    /// Log
//    os_log(OS_LOG_DEFAULT, "Groot: Start");
//    
//    /// Return success
//    return ret;
//    
//    /// Handle failed start
//fail:
//    os_log(OS_LOG_DEFAULT, "Groot: Failed to start");
//    Stop(provider, SUPERDISPATCH);
//    return ret;
//}
//
//kern_return_t IMPL(gamepad_driver_user, Stop) {
//    
//    /// Initial implementation copied from Karabiner https://github.com/pqrs-org/Karabiner-DriverKit-VirtualHIDDevice/blob/151fefd3f5cdbe00874bd4c25cde0ded9665878f/src/DriverKit/Karabiner-DriverKit-VirtualHIDDevice/org_pqrs_Karabiner_DriverKit_VirtualHIDPointing.cpp#L130C1-L137C1
//    
//    os_log(OS_LOG_DEFAULT, "Groot: Stop");
//    return Stop(provider, SUPERDISPATCH);
//}


/// --- IOHIDDevice ---

/*
kern_return_t gamepad_driver_user::handleReport(uint64_t timestamp, IOMemoryDescriptor* report, uint32_t reportLength, IOHIDReportType reportType, IOOptionBits options) {
    
    
//    IOHIDDevice::handleReport(timestamp, report, reportLength, reportType, options);
    
    return KERN_SUCCESS;
}


kern_return_t gamepad_driver_user::getReport(IOMemoryDescriptor *report, IOHIDReportType reportType, IOOptionBits options, uint32_t completionTimeout, OSAction *action) {

    return KERN_SUCCESS;
}
kern_return_t gamepad_driver_user::setReport(IOMemoryDescriptor *report, IOHIDReportType reportType, IOOptionBits options, uint32_t completionTimeout, OSAction *action) {
    
    return KERN_SUCCESS;
}
//void gamepad_driver_user::CompleteReport(OSAction *action, IOReturn status, uint32_t actualByteCount) {
//    
//}
void gamepad_driver_user::setProperty(OSObject *key, OSObject *value) {
        
}
 */

/// --- IOUserHIDDevice ---

//bool gamepad_driver_user::handleStart(IOService *provider) {
//
//    /// vvv Code is from keyboard sample project Start() method. Probably doesn't make sense here.
//    kern_return_t ret = KERN_SUCCESS;
////    ret = Start(provider, SUPERDISPATCH);
//    os_log(OS_LOG_DEFAULT, "Hello World");
//
//    return ret;
//}
//
//OSDictionary *gamepad_driver_user::newDeviceDescription(void) {
//    return OSDictionaryCreate();
//}
//OSData *gamepad_driver_user::newReportDescriptor(void) {
//    uint8_t *bytes = NULL;
//    return OSDataCreate(bytes, 0);
//}

