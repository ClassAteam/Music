#include "emergencyalarm_int.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT DEVICE_CONNECT;

emergencyalarm_int::light::light(bool* in_clue, bool* out_clue,
                                 bool* is_checked, clrType color, bssType bss)
    : inClue{in_clue}, outClue{out_clue}, isChecked{is_checked}, color{color},
    bss{bss}
{

}

emergencyalarm_int::emergencyalarm_int()
{
    lights.append(new light(&bss_inst.BSS926X1HH, (&DEVICE_CONNECT.OUT_D[2][18]), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS837X1z, (&DEVICE_CONNECT.OUT_D[2][20]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1p, (&DEVICE_CONNECT.OUT_D[2][33]), new bool{},
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
    lights.append(new light(&bss_inst.BSS811X1N, &DEVICE_CONNECT.OUT_D[0][22], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1R, (&bss_inst.BSS811X2H), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1T, (&bss_inst.BSS811X2J), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1V, (&bss_inst.BSS811X2K), new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1Z, &DEVICE_CONNECT.OUT_D[0][4], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1b, &DEVICE_CONNECT.OUT_D[0][5], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1d, &DEVICE_CONNECT.OUT_D[0][6], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1f, &DEVICE_CONNECT.OUT_D[0][7], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1DD, &DEVICE_CONNECT.OUT_D[0][12], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &DEVICE_CONNECT.OUT_D[0][17], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &DEVICE_CONNECT.OUT_D[0][11], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(&bss_inst.BSS811X1Y, &DEVICE_CONNECT.OUT_D[0][78], new bool{},
                            clrType::yellow, bssType::bss939));
    lights.append(new light(new bool{}, &DEVICE_CONNECT.OUT_D[0][72], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1h, &DEVICE_CONNECT.OUT_D[0][116], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1j, &DEVICE_CONNECT.OUT_D[0][117], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1p, &DEVICE_CONNECT.OUT_D[0][102], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1t, &DEVICE_CONNECT.OUT_D[0][103], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1v, &DEVICE_CONNECT.OUT_D[0][97], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1x, &DEVICE_CONNECT.OUT_D[0][106], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1z, &DEVICE_CONNECT.OUT_D[0][107], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs1Otkl, &DEVICE_CONNECT.OUT_D[0][79], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs2Otkl, &DEVICE_CONNECT.OUT_D[0][80], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs3Otkl, &DEVICE_CONNECT.OUT_D[2][81], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.surGs4Otkl, &DEVICE_CONNECT.OUT_D[0][82], new bool{},
                            clrType::yellow, bssType::bss811));

    lights.append(new light(&bss_inst.BSS811X1E, &DEVICE_CONNECT.OUT_D[0][12], new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1G, &DEVICE_CONNECT.OUT_D[0][19], new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1J, (&bss_inst.BSS811X2E), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1L, (&bss_inst.BSS811X2F), new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1n, &DEVICE_CONNECT.OUT_D[0][98], new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1r, &DEVICE_CONNECT.OUT_D[0][99], new bool{},
                            clrType::red, bssType::bss811));
    lights.append(new light(&bss_inst.BSS811X1BB, &DEVICE_CONNECT.OUT_D[0][96], new bool{},
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

    lights.append(new light(&bss_inst.BSS812X5j , &DEVICE_CONNECT.OUT_D[0][104], new bool{},
                            clrType::yellow, bssType::bss811));
    lights.append(new light(&bss_inst.BSS812X5p , &DEVICE_CONNECT.OUT_D[0][105], new bool{},
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
    lights.append(new light(new bool{}, &DEVICE_CONNECT.OUT_D[0][65], new bool{},
                            clrType::yellow, bssType::bss812));

    lights.append(new light(&bss_inst.BSS812X5h , &DEVICE_CONNECT.OUT_D[0][100], new bool{},
                            clrType::red, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5n , &DEVICE_CONNECT.OUT_D[0][101], new bool{},
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
    lights.append(new light(&bss_inst.BSS812X5E , &DEVICE_CONNECT.OUT_D[0][74], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5G , &DEVICE_CONNECT.OUT_D[0][75], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5J , &DEVICE_CONNECT.OUT_D[0][76], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5L , &DEVICE_CONNECT.OUT_D[0][77], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5N , &DEVICE_CONNECT.OUT_D[0][73], new bool{},
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
    lights.append(new light(&bss_inst.BSS812X5r  , &DEVICE_CONNECT.OUT_D[0][69], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5z  , (&bss_inst.BSS812X6a), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5BB  , (&bss_inst.BSS812X6b), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5DD  , (&bss_inst.BSS812X6c), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5FF  , (&bss_inst.BSS812X6d), new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812_vkl_rt, &DEVICE_CONNECT.OUT_D[0][66], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812_vkl_ft  ,&DEVICE_CONNECT.OUT_D[0][67], new bool{},
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
    lights.append(new light(&bss_inst.BSS913X3E, &DEVICE_CONNECT.OUT_D[0][108], new bool{},
                            clrType::yellow, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3G, &DEVICE_CONNECT.OUT_D[0][109], new bool{},
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
    lights.append(new light(&bss_inst.BSS913X3C, &DEVICE_CONNECT.OUT_D[0][115], new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3J, &DEVICE_CONNECT.OUT_D[0][112], new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3L, &DEVICE_CONNECT.OUT_D[0][111], new bool{},
                            clrType::white, bssType::bss913));
    lights.append(new light(&bss_inst.BSS913X3N, &DEVICE_CONNECT.OUT_D[0][110], new bool{},
                            clrType::white, bssType::bss913));

    lights.append(new light(&bss_inst.BSS824X1D, &DEVICE_CONNECT.OUT_D[1][18], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1J, &DEVICE_CONNECT.OUT_D[1][12], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1M, (&bss_inst.BSS824X2F), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1N, &DEVICE_CONNECT.OUT_D[1][6], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1T, &DEVICE_CONNECT.OUT_D[1][4], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1V, &DEVICE_CONNECT.OUT_D[1][4], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1b, (&bss_inst.BSS824X2N), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1f, &DEVICE_CONNECT.OUT_D[1][5], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1h, (&bss_inst.BSS824X2S), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1j, (&bss_inst.BSS824X2T), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1A, (&bss_inst.BSS824X2A), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1n, &DEVICE_CONNECT.OUT_D[1][29], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1p, &DEVICE_CONNECT.OUT_D[1][31], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1r, &DEVICE_CONNECT.OUT_D[1][33], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1t, &DEVICE_CONNECT.OUT_D[1][27], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1v, &DEVICE_CONNECT.OUT_D[1][26], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1x, (&bss_inst.BSS824X2Z), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1z, &DEVICE_CONNECT.OUT_D[1][45], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1BB, &DEVICE_CONNECT.OUT_D[1][46], new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1DD, (&bss_inst.BSS824X2c), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1FF, (&bss_inst.BSS824X2d), new bool{},
                            clrType::yellow, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1HH, &DEVICE_CONNECT.OUT_D[1][52], new bool{},
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

    lights.append(new light(&bss_inst.BSS824X1R, &DEVICE_CONNECT.OUT_D[1][7], new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1E, &DEVICE_CONNECT.OUT_D[1][47], new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X1KK, (&bss_inst.BSS824X2f), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3N, (&bss_inst.BSS824X2p), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3R, (&bss_inst.BSS824X2q), new bool{},
                            clrType::white, bssType::bss824));
    lights.append(new light(&bss_inst.BSS824X3E, &DEVICE_CONNECT.OUT_D[1][49], new bool{},
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
    lights.append(new light(&bss_inst.BSS825X7R, &DEVICE_CONNECT.OUT_D[1][50], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5v, &DEVICE_CONNECT.OUT_D[1][28], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5x, &DEVICE_CONNECT.OUT_D[1][30], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5z, &DEVICE_CONNECT.OUT_D[1][32], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5z, (&bss_inst.BSS825X6a), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5KK, &DEVICE_CONNECT.OUT_D[1][53], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825X5MM, &DEVICE_CONNECT.OUT_D[1][54], new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, (&bss_inst.BSS825PROG), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, (&bss_inst.BSS825PROG), new bool{},
                            clrType::white, bssType::bss825));
    lights.append(new light(&bss_inst.BSS825PR, &DEVICE_CONNECT.OUT_D[1][44], new bool{},
                            clrType::white, bssType::bss825));

    lights.append(new light(&bss_inst.BSS926X1C, (&DEVICE_CONNECT.OUT_D[2][86]), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1G, &DEVICE_CONNECT.OUT_D[2][88], new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1d, &DEVICE_CONNECT.OUT_D[2][106], new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3V, &DEVICE_CONNECT.OUT_D[2][115], new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1x, (&DEVICE_CONNECT.OUT_D[2][24]), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1BB, (&DEVICE_CONNECT.OUT_D[2][15]), new bool{},
                            clrType::yellow, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1FF, (&DEVICE_CONNECT.OUT_D[2][17]), new bool{},
                            clrType::yellow, bssType::bss926));

    lights.append(new light(&bss_inst.BSS926X1A, (&DEVICE_CONNECT.OUT_D[2][85]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1E, (&DEVICE_CONNECT.OUT_D[2][87]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1J, &DEVICE_CONNECT.OUT_D[2][89], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1L, (&DEVICE_CONNECT.OUT_D[2][93]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1N, (&DEVICE_CONNECT.OUT_D[2][94]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1R, &DEVICE_CONNECT.OUT_D[2][104], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1T, &DEVICE_CONNECT.OUT_D[2][105], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1V, &DEVICE_CONNECT.OUT_D[2][114], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1X, &DEVICE_CONNECT.OUT_D[2][113], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1Z, &DEVICE_CONNECT.OUT_D[2][122], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1b, &DEVICE_CONNECT.OUT_D[2][123], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1f, &DEVICE_CONNECT.OUT_D[2][80], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1h, &DEVICE_CONNECT.OUT_D[2][81], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1j, &DEVICE_CONNECT.OUT_D[2][82], new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1n, (&bss_inst.BSS926X2U), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1t, (&bss_inst.BSS926X2U), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1p, (&bss_inst.BSS926X2V), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1r, (&bss_inst.BSS926X2W), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1z, (&DEVICE_CONNECT.OUT_D[2][13]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1DD, (&DEVICE_CONNECT.OUT_D[2][16]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1KK, (&bss_inst.BSS926X2f), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X1MM, (&DEVICE_CONNECT.OUT_D[2][11]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3A, (&bss_inst.BSS926X2h), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3C, (&DEVICE_CONNECT.OUT_D[2][27]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3E, (&DEVICE_CONNECT.OUT_D[2][28]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3H, (&bss_inst.BSS926X2k), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3J, (&DEVICE_CONNECT.OUT_D[2][21]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3L, (&DEVICE_CONNECT.OUT_D[2][24]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3N, (&DEVICE_CONNECT.OUT_D[2][36]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3R, (&DEVICE_CONNECT.OUT_D[2][54]), new bool{},
                            clrType::white, bssType::bss926));
    lights.append(new light(&bss_inst.BSS926X3T, (&DEVICE_CONNECT.OUT_D[2][55]), new bool{},
                            clrType::white, bssType::bss926));

    lights.append(new light(&bss_inst.BSS837X1A, (&bss_inst.BSS837X2A), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1C, (&bss_inst.BSS837X2B), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1E, (&bss_inst.BSS837X2C), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1G, (&bss_inst.BSS837X2D), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1J, (&DEVICE_CONNECT.OUT_D[2][5]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1N, (&DEVICE_CONNECT.OUT_D[2][9]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1R, (&DEVICE_CONNECT.OUT_D[2][6]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1V, (&DEVICE_CONNECT.OUT_D[2][10]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1L, (&DEVICE_CONNECT.OUT_D[2][7]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1X, &DEVICE_CONNECT.OUT_D[2][61], new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1Z, &DEVICE_CONNECT.OUT_D[2][62], new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1b, (&DEVICE_CONNECT.OUT_D[2][30]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1d, (&DEVICE_CONNECT.OUT_D[2][32]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1f, (&DEVICE_CONNECT.OUT_D[2][31]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1h, (&DEVICE_CONNECT.OUT_D[2][35]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1j, (&DEVICE_CONNECT.OUT_D[2][25]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1r, (&DEVICE_CONNECT.OUT_D[2][34]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1t, (&DEVICE_CONNECT.OUT_D[2][22]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1x, (&DEVICE_CONNECT.OUT_D[2][19]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1BB, (&DEVICE_CONNECT.OUT_D[2][57]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1DD, (&DEVICE_CONNECT.OUT_D[2][58]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1KK, (&DEVICE_CONNECT.OUT_D[2][59]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1MM, (&DEVICE_CONNECT.OUT_D[2][52]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3G, (&DEVICE_CONNECT.OUT_D[2][59]), new bool{},
                            clrType::yellow, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3J, (&DEVICE_CONNECT.OUT_D[2][46]), new bool{},
                            clrType::yellow, bssType::bss837));

    lights.append(new light(&bss_inst.BSS837X1p, (&DEVICE_CONNECT.OUT_D[2][32]), new bool{},
                            clrType::red, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3C, (&DEVICE_CONNECT.OUT_D[2][50]), new bool{},
                            clrType::red, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3N, (&DEVICE_CONNECT.OUT_D[2][48]), new bool{},
                            clrType::red, bssType::bss837));

    lights.append(new light(&bss_inst.BSS837X1T, (&bss_inst.BSS837X2J), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1n, (&DEVICE_CONNECT.OUT_D[2][26]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1v, (&DEVICE_CONNECT.OUT_D[2][23]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1FF, (&DEVICE_CONNECT.OUT_D[2][56]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X1HH, (&DEVICE_CONNECT.OUT_D[2][45]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3A, (&DEVICE_CONNECT.OUT_D[2][53]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3E, (&DEVICE_CONNECT.OUT_D[2][51]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3L, (&DEVICE_CONNECT.OUT_D[2][47]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3R, (&DEVICE_CONNECT.OUT_D[2][22]), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS837X3T, (&bss_inst.BSS837X2r), new bool{},
                            clrType::white, bssType::bss837));
    lights.append(new light(&bss_inst.BSS838X5A, (&DEVICE_CONNECT.OUT_D[2][37]), new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5J, &DEVICE_CONNECT.OUT_D[2][43], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5T, &DEVICE_CONNECT.OUT_D[2][90], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5V, &DEVICE_CONNECT.OUT_D[2][91], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5Z, &DEVICE_CONNECT.OUT_D[2][95], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5d, &DEVICE_CONNECT.OUT_D[2][99], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5h, &DEVICE_CONNECT.OUT_D[2][102], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5n, &DEVICE_CONNECT.OUT_D[2][100], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5p, &bss_inst.BSS838X6V, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5v, &DEVICE_CONNECT.OUT_D[2][109], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5z, &DEVICE_CONNECT.OUT_D[2][111], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5DD, &DEVICE_CONNECT.OUT_D[2][118], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5HH, &DEVICE_CONNECT.OUT_D[2][120], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7E, &bss_inst.BSS838X6j, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7J, &bss_inst.BSS838X6m, new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7R, &DEVICE_CONNECT.OUT_D[2][108], new bool{},
                            clrType::yellow, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7T, &DEVICE_CONNECT.OUT_D[2][117], new bool{},
                            clrType::yellow, bssType::bss838));

    lights.append(new light(&bss_inst.BSS838X5E, &DEVICE_CONNECT.OUT_D[2][39], new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5N, &DEVICE_CONNECT.OUT_D[2][41], new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7C, &DEVICE_CONNECT.OUT_D[2][79], new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7G, &bss_inst.BSS838X6k, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7L, &bss_inst.BSS838X6n, new bool{},
                            clrType::red, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X7N, &DEVICE_CONNECT.OUT_D[2][69], new bool{},
                            clrType::red, bssType::bss838));


    lights.append(new light(&bss_inst.BSS838X5C, &DEVICE_CONNECT.OUT_D[2][38], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5G, &DEVICE_CONNECT.OUT_D[2][40], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5L, &DEVICE_CONNECT.OUT_D[2][44], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5R, &DEVICE_CONNECT.OUT_D[2][42], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5X, &DEVICE_CONNECT.OUT_D[2][92], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5b, &DEVICE_CONNECT.OUT_D[2][96], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5f, &DEVICE_CONNECT.OUT_D[2][99], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5j, &DEVICE_CONNECT.OUT_D[2][103], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5x, &DEVICE_CONNECT.OUT_D[2][110], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5BB, &DEVICE_CONNECT.OUT_D[2][112], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5FF, &DEVICE_CONNECT.OUT_D[2][119], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5KK, &DEVICE_CONNECT.OUT_D[2][121], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS838X5r, &DEVICE_CONNECT.OUT_D[2][97], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.zakr_om1, &DEVICE_CONNECT.OUT_D[2][107], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.zakr_om2, &DEVICE_CONNECT.OUT_D[2][116], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&antiicing.PONdv4, &DEVICE_CONNECT.OUT_D[0][1], new bool{},
                            clrType::white, bssType::bss838));
    lights.append(new light(&bss_inst.BSS812X5v, &DEVICE_CONNECT.OUT_D[1][64], new bool{},
                            clrType::white, bssType::bss812));
    lights.append(new light(&bss_inst.BSS812X5x, &DEVICE_CONNECT.OUT_D[1][64], new bool{},
                            clrType::white, bssType::bss812));
    //blinking lights
    lights.append(new light(&bss_inst.BSS811X1E, &DEVICE_CONNECT.OUT_D[0][12], new bool{},
                            clrType::white, bssType::bss812));
}

void emergencyalarm_int::updateLogic()
{
    emergencyalarm_1();
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
