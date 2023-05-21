 #include <libhackrf/hackrf.h>
namespace sdr{
/**
 * @class HackRF
 * @brief This class represents the APIs for using the HackRF One software defined radio
*/
class HackRF {
    public:
    HackRF();
    ~HackRF(){_exit_libhackrf();}
    private: 
    hackrf_device* _device_ptr;

    /**
     * @fn _initialize_libhackrf() 
     * @brief This function should be called befory any other libhackrf function,
     *          initializes libusb and can be safely called multiple times
     * @return void
    */
    void _initialize_libhackrf(); 
/**
     * @fn _exit_libhackrf() 
     * @brief This function should be called before exit and can be safely called multiple times.
     *          No other libhackrf functions should be called after it
     * @return void
    */
    void _exit_libhackrf(); 
/**
 * @fn _handle_device_list
 * @brief This function checks how many hackrf devices are present in the system.
 *          If there is more than one device the user is prompted to choose which one
 *          to interface to. The private member <_device_ptr> is set
 * @return void
*/
void _handle_device_list();


};
}


