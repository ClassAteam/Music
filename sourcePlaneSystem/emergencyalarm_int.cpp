#include "emergencyalarm_int.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;

emergencyalarm_int::light::light(bool* in_clue, bool* out_clue,
                                 bool* is_checked, clrType color, bssType bss)
    : inClue{in_clue}, outClue{out_clue}, isChecked{is_checked}, color{color},
    bss{bss}
{

}

emergencyalarm_int::emergencyalarm_int()
{
//    lights.append(new light(&bss_inst.BSS926X1HH, (&bss_inst.BSS926X2e), new bool{},
//                            clrType::yellow, bssType::bss926));
lights.append(new light(&bss_inst.BSS926X1HH, (&pDev->OUT_D[2][18]), new bool{},
                        clrType::yellow, bssType::bss926));
//    lights.append(new light(&bss_inst.BSS837X1z, (&bss_inst.BSS837X2a), new bool{},
//                            clrType::yellow, bssType::bss837));
lights.append(new light(&bss_inst.BSS837X1z, (&pDev->OUT_D[2][20]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS939X1B, (&bss_inst.BSS939X2A), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS939X1D, (&bss_inst.BSS939X2B), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS939X1E, (&bss_inst.BSS939X2C), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS939X1J, (&bss_inst.BSS939X2E), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS939X1L, (&bss_inst.BSS939X2F), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&svs_otkaz, (&bss_inst.BSS939X2F), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&svs_net_rezerva, (&bss_inst.BSS939X2J), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&ins_otkaz, (&bss_inst.BSS939X2K), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&ins_net_rezerva, (&bss_inst.BSS939X2L), new bool{},
                            clrType::yellow, bssType::bss939));

    lights.append(new light(&bss_inst.BSS939X1G, (&bss_inst.BSS939X2D), new bool{},
                            clrType::red, bssType::bss939));
    lights.append(new light(&bss_inst.BSS939X1N, (&bss_inst.BSS939X2G), new bool{},
                            clrType::red, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1B, (&bss_inst.BSS811X2A), new bool{},
                            clrType::yellow, bssType::bss939));

    lights.append(new light(&bss_inst.BSS811X1D, (&bss_inst.BSS811X2B), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1N, (&bss_inst.BSS811X2G), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1R, (&bss_inst.BSS811X2H), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1T, (&bss_inst.BSS811X2J), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1V, (&bss_inst.BSS811X2K), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1Z, (&bss_inst.BSS811X2M), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1b, (&bss_inst.BSS811X2N), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1d, (&bss_inst.BSS811X2P), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1f, (&bss_inst.BSS811X2R), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1DD, (&bss_inst.BSS811X2c), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &pDev->OUT_D[0][17], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &pDev->OUT_D[0][11], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1Y, (&bss_inst.BSS811X2L), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &pDev->OUT_D[0][72], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1h, (&bss_inst.BSS811X2S), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1j, (&bss_inst.BSS811X2T), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1p, (&bss_inst.BSS811X2V), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1t, (&bss_inst.BSS811X2X), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1v, (&bss_inst.BSS811X2Y), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1x, (&bss_inst.BSS811X2Z), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1z, (&bss_inst.BSS811X2a), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs1Otkl, (&bss_inst.BSS811X2d), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs2Otkl, (&bss_inst.BSS811X2e), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs3Otkl, (&bss_inst.BSS811X2f), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs4Otkl, (&bss_inst.BSS811X2g), new bool{},
                            clrType::yellow, bssType::bss811));

    lights.append(new light(&bss_inst.BSS811X1E, (&bss_inst.BSS811X2C), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1G, (&bss_inst.BSS811X2D), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1J, (&bss_inst.BSS811X2E), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1L, (&bss_inst.BSS811X2F), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1n, (&bss_inst.BSS811X2U), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1r, (&bss_inst.BSS811X2W), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1BB, (&bss_inst.BSS811X2b), new bool{},
                            clrType::red, bssType::bss811));

    lights.append(new light(&bss_inst.BSS811X3A, (&bss_inst.BSS811X2h), new bool{},
                            clrType::white, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X3C, (&bss_inst.BSS811X2l), new bool{},
                            clrType::white, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X3D, (&bss_inst.BSS811X2j), new bool{},
                            clrType::white, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X3E, (&bss_inst.BSS811X2k), new bool{},
                            clrType::white, bssType::bss811));
    lights.append(new light(new bool{}, (&bss_inst.BSS811X2p), new bool{},
                            clrType::white, bssType::bss811));
    lights.append(new light(new bool{}, (&bss_inst.BSS811X2q), new bool{},
                            clrType::white, bssType::bss811));

    lights.append(new light(&bss_inst.BSS812X5j , (&bss_inst.BSS812X6T ), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS812X5p , (&bss_inst.BSS812X6V ), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS812X5HH , (&bss_inst.BSS812X6e ), new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6j), new bool{},
                            clrType::yellow, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6k), new bool{},
                            clrType::yellow, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6m), new bool{},
                            clrType::yellow, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6q), new bool{},
                            clrType::yellow, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6n), new bool{},
                            clrType::yellow, bssType::bss812));

    lights.append(new light(&bss_inst.BSS812X5h , (&bss_inst.BSS812X6S ), new bool{},
                            clrType::red, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5n , (&bss_inst.BSS812X6U ), new bool{},
                            clrType::red, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6g), new bool{},
                            clrType::red, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6h), new bool{},
                            clrType::red, bssType::bss812));
    lights.append(new light(new bool{}, (&bss_inst.BSS812X6i), new bool{},
                            clrType::red, bssType::bss812));

    lights.append(new light(&bss_inst.BSS812X5B , (&bss_inst.BSS812X6A ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5D , (&bss_inst.BSS812X6B ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5E , (&bss_inst.BSS812X6C ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5G , (&bss_inst.BSS812X6D ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5J , (&bss_inst.BSS812X6E ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5L , (&bss_inst.BSS812X6F ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5N , (&bss_inst.BSS812X6G ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5R , (&bss_inst.BSS812X6H ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5T , (&bss_inst.BSS812X6J ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5V , (&bss_inst.BSS812X6K ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5X , (&bss_inst.BSS812X6L ), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5Z , (&bss_inst.BSS812X5b ), new bool{},
                            clrType::white, bssType::bss812));


    lights.append(new light(&bss_inst.BSS812X5t  , (&bss_inst.BSS812X6X), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5r  , (&bss_inst.BSS812X6W), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5z  , (&bss_inst.BSS812X6a), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5BB  , (&bss_inst.BSS812X6b), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5DD  , (&bss_inst.BSS812X6c), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5FF  , (&bss_inst.BSS812X6d), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812_vkl_rt  , (&bss_inst.BSS812X6p), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812_vkl_ft  , (&bss_inst.BSS812X6r), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5KK  , (&bss_inst.BSS812X6f), new bool{},
                            clrType::white, bssType::bss812));

    lights.append(new light(&bss_inst.BSS913X1C, (&bss_inst.BSS913X2B), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1E, (&bss_inst.BSS913X2C), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1G, (&bss_inst.BSS913X2D), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1J, (&bss_inst.BSS913X2E), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1L, (&bss_inst.BSS913X2F), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1N, (&bss_inst.BSS913X2G), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1T, (&bss_inst.BSS913X2J), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1V, (&bss_inst.BSS913X2K), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1X, (&bss_inst.BSS913X2L), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1Z, (&bss_inst.BSS913X2M), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1b, (&bss_inst.BSS913X2N), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1d, (&bss_inst.BSS913X2P), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1h, (&bss_inst.BSS913X2S), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1j, (&bss_inst.BSS913X2T), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1n, (&bss_inst.BSS913X2U), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1p, (&bss_inst.BSS913X2V), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1r, (&bss_inst.BSS913X2W), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1t, (&bss_inst.BSS913X2X), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1x, (&bss_inst.BSS913X2Z), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1z, (&bss_inst.BSS913X2a), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1BB, (&bss_inst.BSS913X2b), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1DD, (&bss_inst.BSS913X2c), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1FF, (&bss_inst.BSS913X2d), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1HH, (&bss_inst.BSS913X2e), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3E, (&bss_inst.BSS913X2j), new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3G, (&bss_inst.BSS913X2k), new bool{},
                            clrType::yellow, bssType::bss913));

    lights.append(new light(&bss_inst.BSS913X1A, (&bss_inst.BSS913X2A), new bool{},
                            clrType::red, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1R, (&bss_inst.BSS913X2H), new bool{},
                            clrType::red, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1f, (&bss_inst.BSS913X2R), new bool{},
                            clrType::red, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X1v, (&bss_inst.BSS913X2Y), new bool{},
                            clrType::red, bssType::bss913));

    lights.append(new light(&bss_inst.BSS913X3A, (&bss_inst.BSS913X2h), new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3C, (&bss_inst.BSS913X2i), new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3J, (&bss_inst.BSS913X2m), new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3L, (&bss_inst.BSS913X2n), new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3N, (&bss_inst.BSS913X2p), new bool{},
                            clrType::white, bssType::bss913));

    lights.append(new light(&bss_inst.BSS824X1D, (&bss_inst.BSS824X2B), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1J, (&bss_inst.BSS824X2E), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1M, (&bss_inst.BSS824X2F), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1N, (&bss_inst.BSS824X2G), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1T, (&bss_inst.BSS824X2J), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1V, (&bss_inst.BSS824X2J), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1b, (&bss_inst.BSS824X2N), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1f, (&bss_inst.BSS824X2R), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1h, (&bss_inst.BSS824X2S), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1j, (&bss_inst.BSS824X2T), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1A, (&bss_inst.BSS824X2A), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1n, (&bss_inst.BSS824X2U), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1p, (&bss_inst.BSS824X2V), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1r, (&bss_inst.BSS824X2W), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1t, (&bss_inst.BSS824X2X), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1v, (&bss_inst.BSS824X2Y), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1x, (&bss_inst.BSS824X2Z), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1z, (&bss_inst.BSS824X2a), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1BB, (&bss_inst.BSS824X2b), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1DD, (&bss_inst.BSS824X2c), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1FF, (&bss_inst.BSS824X2d), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1HH, (&bss_inst.BSS824X2e), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3L, (&bss_inst.BSS824X2n), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3T, (&bss_inst.BSS824X2r), new bool{},
                            clrType::yellow, bssType::bss824));

    lights.append(new light(&bss_inst.BSS824X1X, (&bss_inst.BSS824X2L), new bool{},
                            clrType::red, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1Z, (&bss_inst.BSS824X2M), new bool{},
                            clrType::red, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3G, (&bss_inst.BSS824X2k), new bool{},
                            clrType::red, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3J, (&bss_inst.BSS824X2m), new bool{},
                            clrType::red, bssType::bss824));

    lights.append(new light(&bss_inst.BSS824X1R, (&bss_inst.BSS824X2H), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1E, (&bss_inst.BSS824X2C), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1KK, (&bss_inst.BSS824X2f), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3N, (&bss_inst.BSS824X2p), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3R, (&bss_inst.BSS824X2q), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3E, (&bss_inst.BSS824X2i), new bool{},
                            clrType::white, bssType::bss824));

    lights.append(new light(&bss_inst.BSS825X5A, (&bss_inst.BSS825X6A), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5C, (&bss_inst.BSS825X6B), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5E, (&bss_inst.BSS825X6C), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5G, (&bss_inst.BSS825X6D), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5G, (&bss_inst.BSS825X6D), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6r), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6m), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6m), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6n), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6p), new bool{},
                            clrType::yellow, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5L, (&bss_inst.BSS825X6F), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5f, (&bss_inst.BSS825X6R), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5N, (&bss_inst.BSS825X6G), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5h, (&bss_inst.BSS825X6S), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5R, (&bss_inst.BSS825X6H), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5j, (&bss_inst.BSS825X6T), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5T, (&bss_inst.BSS825X6J), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5n, (&bss_inst.BSS825X6U), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6i), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6j), new bool{},
                            clrType::red, bssType::bss825));
    lights.append(new light(new bool{}, (&bss_inst.BSS825X6k), new bool{},
                            clrType::red, bssType::bss825));

    lights.append(new light(&bss_inst.BSS825X5J, (&bss_inst.BSS825X6E), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5V, (&bss_inst.BSS825X6K), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5FF, (&bss_inst.BSS825X6d), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5HH, (&bss_inst.BSS825X6e), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5X, (&bss_inst.BSS825X6L), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5Z, (&bss_inst.BSS825X6M), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5b, (&bss_inst.BSS825X6N), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5d, (&bss_inst.BSS825X6P), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5r, (&bss_inst.BSS825X6W), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5t, (&bss_inst.BSS825X6X), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X7R, (&bss_inst.BSS825X6q), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5v, (&bss_inst.BSS825X6Y), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5x, (&bss_inst.BSS825X6Z), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5z, (&bss_inst.BSS825X6a), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5z, (&bss_inst.BSS825X6a), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5KK, (&bss_inst.BSS825X6f), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5MM, (&bss_inst.BSS825X6g), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, (&bss_inst.BSS825PROG), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, (&bss_inst.BSS825PROG), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, (&bss_inst.BSS825_prog), new bool{},
                            clrType::white, bssType::bss825));

    lights.append(new light(&bss_inst.BSS926X1C, (&bss_inst.BSS926X2B), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1G, (&bss_inst.BSS926X2D), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1d, (&bss_inst.BSS926X2p), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3V, (&bss_inst.BSS926X2s), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1x, (&bss_inst.BSS926X2z), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1BB, (&bss_inst.BSS926X2b), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1FF, (&bss_inst.BSS926X2d), new bool{},
                            clrType::yellow, bssType::bss926));

    lights.append(new light(&bss_inst.BSS926X1A, (&bss_inst.BSS926X2A), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1E, (&bss_inst.BSS926X2C), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1J, (&bss_inst.BSS926X2E), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1L, (&bss_inst.BSS926X2F), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1N, (&bss_inst.BSS926X2G), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1R, (&bss_inst.BSS926X2H), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1T, (&bss_inst.BSS926X2J), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1V, (&bss_inst.BSS926X2K), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1X, (&bss_inst.BSS926X2L), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1Z, (&bss_inst.BSS926X2M), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1b, (&bss_inst.BSS926X2N), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1f, (&bss_inst.BSS926X2R), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1h, (&bss_inst.BSS926X2S), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1j, (&bss_inst.BSS926X2T), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1n, (&bss_inst.BSS926X2U), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1t, (&bss_inst.BSS926X2U), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1p, (&bss_inst.BSS926X2V), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1r, (&bss_inst.BSS926X2W), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1z, (&bss_inst.BSS926X2a), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1DD, (&bss_inst.BSS926X2c), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1KK, (&bss_inst.BSS926X2f), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1MM, (&bss_inst.BSS926X2g), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3A, (&bss_inst.BSS926X2h), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3C, (&bss_inst.BSS926X2i), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3E, (&bss_inst.BSS926X2j), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3H, (&bss_inst.BSS926X2k), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3J, (&bss_inst.BSS926X2m), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3L, (&bss_inst.BSS926X2n), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3N, (&bss_inst.BSS926X2P), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3R, (&bss_inst.BSS926X2q), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3T, (&bss_inst.BSS926X2r), new bool{},
                            clrType::white, bssType::bss926));

    lights.append(new light(&bss_inst.BSS837X1A, (&bss_inst.BSS837X2A), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1C, (&bss_inst.BSS837X2B), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1E, (&bss_inst.BSS837X2C), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1G, (&bss_inst.BSS837X2D), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1J, (&bss_inst.BSS837X2E), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1J, (&bss_inst.BSS837X2E), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1N, (&bss_inst.BSS837X2G), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1R, (&bss_inst.BSS837X2H), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1V, (&bss_inst.BSS837X2K), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1L, (&bss_inst.BSS837X2F), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1X, (&bss_inst.BSS837X2L), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1Z, (&bss_inst.BSS837X2M), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1b, (&bss_inst.BSS837X2N), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1d, (&bss_inst.BSS837X2P), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1f, (&bss_inst.BSS837X2R), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1h, (&bss_inst.BSS837X2S), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1j, (&bss_inst.BSS837X2T), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1r, (&bss_inst.BSS837X2W), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1t, (&bss_inst.BSS837X2X), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1x, (&bss_inst.BSS837X2Z), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1BB, (&bss_inst.BSS837X2b), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1DD, (&bss_inst.BSS837X2c), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1KK, (&bss_inst.BSS837X2f), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1MM, (&bss_inst.BSS837X2g), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3G, (&bss_inst.BSS837X2k), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3J, (&bss_inst.BSS837X2m), new bool{},
                            clrType::yellow, bssType::bss837));

    lights.append(new light(&bss_inst.BSS837X1p, (&bss_inst.BSS837X2V), new bool{},
                            clrType::red, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3C, (&bss_inst.BSS837X2i), new bool{},
                            clrType::red, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3N, (&bss_inst.BSS837X2p), new bool{},
                            clrType::red, bssType::bss837));

    lights.append(new light(&bss_inst.BSS837X1T, (&bss_inst.BSS837X2J), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1n, (&bss_inst.BSS837X2U), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1v, (&bss_inst.BSS837X2Y), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1FF, (&bss_inst.BSS837X2d), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1HH, (&bss_inst.BSS837X2e), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3A, (&bss_inst.BSS837X2h), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3E, (&bss_inst.BSS837X2j), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3L, (&bss_inst.BSS837X2n), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3R, (&bss_inst.BSS837X2q), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3T, (&bss_inst.BSS837X2r), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS838X5A, &(bss_inst.BSS838X6A), new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5J, &bss_inst.BSS838X6E, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5T, &bss_inst.BSS838X6J, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5V, &bss_inst.BSS838X6K, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5Z, &bss_inst.BSS838X6M, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5d, &bss_inst.BSS838X6P, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5h, &bss_inst.BSS838X6S, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5n, &bss_inst.BSS838X6U, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5p, &bss_inst.BSS838X6V, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5v, &bss_inst.BSS838X6Y, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5z, &bss_inst.BSS838X6a, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5DD, &bss_inst.BSS838X6c, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5HH, &bss_inst.BSS838X6e, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7E, &bss_inst.BSS838X6j, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7J, &bss_inst.BSS838X6m, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7R, &bss_inst.BSS838X6q, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7T, &bss_inst.BSS838X6r, new bool{},
                            clrType::yellow, bssType::bss838));

    lights.append(new light(&bss_inst.BSS838X5E, &bss_inst.BSS838X6C, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5N, &bss_inst.BSS838X6G, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7C, &bss_inst.BSS838X6i, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7G, &bss_inst.BSS838X6k, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7L, &bss_inst.BSS838X6n, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7N, &bss_inst.BSS838X6p, new bool{},
                            clrType::red, bssType::bss838));


    lights.append(new light(&bss_inst.BSS838X5C, &bss_inst.BSS838X6B, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5G, &bss_inst.BSS838X6D, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5L, &bss_inst.BSS838X6F, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5R, &bss_inst.BSS838X6H, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5X, &bss_inst.BSS838X6L, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5b, &bss_inst.BSS838X6N, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5f, &bss_inst.BSS838X6R, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5j, &bss_inst.BSS838X6T, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5x, &bss_inst.BSS838X6Z, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5BB, &bss_inst.BSS838X6b, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5FF, &bss_inst.BSS838X6d, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5KK, &bss_inst.BSS838X6f, new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5r, &bss_inst.BSS838X6W, new bool{},
                            clrType::white, bssType::bss838));
}

void emergencyalarm_int::updateLogic()
{
    emergencyalarm_1();
    emergencyalarm_2();
    emergencyalarm_3();
    emergencyalarm_4();
    emergencyalarm_5();
    emergencyalarm_6();
    emergencyalarm_7();
    emergencyalarm_8();
    emergencyalarm_9();
}


void emergencyalarm_int::lamp_blink(bool &inpClue, bool &lamp, int &blink)
{
    if(inpClue)
    {
        blink++;
        if((blink * TICK) < 100)
        {
            lamp = false;
        }
        if(((blink * TICK)) >= 100)
        {
            lamp = true;
            if(blink * TICK >= 200) blink = 0;
        }
    }
    else
    {
        blink = 0;
    }
}
