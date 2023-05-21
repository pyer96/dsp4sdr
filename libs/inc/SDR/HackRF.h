namespace sdr{
/**
 * @class HackRF
 * @brief This class represents the APIs for using the HackRF One software defined radio
*/
class HackRF {
    private: 
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



    public:
    HackRF();
    ~HackRF(){_exit_libhackrf();}
};
}


