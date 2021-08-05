#include "emergencyalarm_int.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT DEVICE_CONNECT;

emergencyalarm_int::light::light(QString mname, bool* in_clue, bool* out_clue,
                                 clrType color, bssType bss)
    : name{mname}, inClue{in_clue}, outClue{out_clue}, color{color}, bss{bss}
{

}
emergencyalarm_int::light::light(QString mname, bool* in_clue, bool* out_clue,
                                 clrType color, bssType bss, bool isblinking)
    : name{mname}, inClue{in_clue}, outClue{out_clue}, color{color}, bss{bss},
    isBlnkng{isblinking}
{

}

emergencyalarm_int::emergencyalarm_int()
{
    lights.append(new light("BSS926X1HH", &bss_inst.BSS926X1HH, (&DEVICE_CONNECT.OUT_D[2][18]),
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS837X1z", &bss_inst.BSS837X1z, (&DEVICE_CONNECT.OUT_D[2][20]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1p", &bss_inst.pravOtAkk, (&DEVICE_CONNECT.OUT_D[2][33]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS939X1B", &bss_inst.BSS939X1B, (&bss_inst.BSS939X2A),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS939X1D", &bss_inst.BSS939X1D, (&bss_inst.BSS939X2B),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS939X1E", &bss_inst.BSS939X1E, (&bss_inst.BSS939X2C),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS939X1J", &bss_inst.BSS939X1J, (&bss_inst.BSS939X2E),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS939X1L", &bss_inst.BSS939X1L, (&bss_inst.BSS939X2F),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("939X2F",  new bool{}, (&bss_inst.BSS939X2F),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("939X2J", new bool{}, (&bss_inst.BSS939X2J),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("939X2K", new bool{}, (&bss_inst.BSS939X2K),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("939X2L", new bool{}, (&bss_inst.BSS939X2L),
                            clrType::yellow, bssType::bss939));
//    lights.append(new light("BSS939X1G", &bss_inst.BSS939X1G, (&bss_inst.BSS939X2D),
//                            clrType::red, bssType::bss939));
//    lights.append(new light("BSS939X1N", &bss_inst.BSS939X1N, (&bss_inst.BSS939X2G),
//                            clrType::red, bssType::bss939));
    lights.append(new light("BSS811X1B", &bss_inst.BSS811X1B, (&bss_inst.BSS811X2A),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1D", &bss_inst.BSS811X1D, (&bss_inst.BSS811X2B),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1N", &bss_inst.BSS811X1N, &DEVICE_CONNECT.OUT_D[0][22],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1R", &bss_inst.BSS811X1R, (&bss_inst.BSS811X2H),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1T", &bss_inst.BSS811X1T, (&bss_inst.BSS811X2J),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1V", &bss_inst.BSS811X1V, (&bss_inst.BSS811X2K),
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1Z", &bss_inst.BSS811X1Z, &DEVICE_CONNECT.OUT_D[0][4],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1b", &bss_inst.BSS811X1b, &DEVICE_CONNECT.OUT_D[0][5],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1d", &bss_inst.BSS811X1d, &DEVICE_CONNECT.OUT_D[0][6],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1f", &bss_inst.BSS811X1f, &DEVICE_CONNECT.OUT_D[0][7],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1DD", &bss_inst.BSS811X1DD, &DEVICE_CONNECT.OUT_D[0][12],
                            clrType::yellow, bssType::bss939));
    lights.append(new light( "uknown input", new bool{}, &DEVICE_CONNECT.OUT_D[0][17],
                            clrType::yellow, bssType::bss939));
    lights.append(new light( "uknown input", new bool{}, &DEVICE_CONNECT.OUT_D[0][11],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS811X1Y", &bss_inst.BSS811X1Y, &DEVICE_CONNECT.OUT_D[0][78],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("uknown", new bool{}, &DEVICE_CONNECT.OUT_D[0][72],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1h", &bss_inst.BSS811X1h, &DEVICE_CONNECT.OUT_D[0][116],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1j", &bss_inst.BSS811X1j, &DEVICE_CONNECT.OUT_D[0][117],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1p", &bss_inst.peregrDv1, &DEVICE_CONNECT.OUT_D[0][102],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1t", &bss_inst.BSS811X1t, &DEVICE_CONNECT.OUT_D[0][103],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1v", &bss_inst.BSS811X1v, &DEVICE_CONNECT.OUT_D[0][97],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1x", &bss_inst.BSS811X1x, &DEVICE_CONNECT.OUT_D[0][106],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1z", &bss_inst.BSS811X1z, &DEVICE_CONNECT.OUT_D[0][107],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("surGs1Otkl", &bss_inst.surGs1Otkl, &DEVICE_CONNECT.OUT_D[0][79],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("surGs2Otkl", &bss_inst.surGs2Otkl, &DEVICE_CONNECT.OUT_D[0][80],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("surGs3Otkl", &bss_inst.surGs3Otkl, &DEVICE_CONNECT.OUT_D[0][81],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("surGs4Otkl", &bss_inst.surGs4Otkl, &DEVICE_CONNECT.OUT_D[0][82],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS811X1E", &bss_inst.BSS811X1E, &DEVICE_CONNECT.OUT_D[0][12],
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1G", &bss_inst.BSS811X1G, &DEVICE_CONNECT.OUT_D[0][19],
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1J", &bss_inst.BSS811X1J, (&bss_inst.BSS811X2E),
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1L", &bss_inst.BSS811X1L, (&bss_inst.BSS811X2F),
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1n", &bss_inst.pozharDv1, &DEVICE_CONNECT.OUT_D[0][98],
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1r", &bss_inst.BSS811X1r, &DEVICE_CONNECT.OUT_D[0][99],
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X1BB", &bss_inst.BSS811X1BB, &DEVICE_CONNECT.OUT_D[0][96],
                            clrType::red, bssType::bss811));
    lights.append(new light("BSS811X3A", &bss_inst.BSS811X3A, (&bss_inst.BSS811X2h),
                            clrType::white, bssType::bss811));
    lights.append(new light("BSS811X3C", &bss_inst.BSS811X3C, (&bss_inst.BSS811X2l),
                            clrType::white, bssType::bss811));
    lights.append(new light("BSS811X3D", &bss_inst.BSS811X3D, (&bss_inst.BSS811X2j),
                            clrType::white, bssType::bss811));
    lights.append(new light("BSS811X3E", &bss_inst.BSS811X3E, (&bss_inst.BSS811X2k),
                            clrType::white, bssType::bss811));
    lights.append(new light("BSS811X2p", &bss_inst.BSS811X2p, new bool{}, clrType::white,
                            bssType::bss811));
    lights.append(new light("BSS811X2q", &bss_inst.BSS811X2q, new bool{}, clrType::white,
                            bssType::bss811));
    lights.append(new light("BSS812X5j", &bss_inst.BSS812X5j , &DEVICE_CONNECT.OUT_D[0][104],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS812X5p", &bss_inst.BSS812X5p , &DEVICE_CONNECT.OUT_D[0][105],
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS812X5HH", &bss_inst.BSS812X5HH , (&bss_inst.BSS812X6e ),
                            clrType::yellow, bssType::bss811));
    lights.append(new light("BSS812X6j", &bss_inst.BSS812X6j, new bool{}, clrType::yellow,
                            bssType::bss812));
    lights.append(new light("BSS812X6k", &bss_inst.BSS812X6k, new bool{}, clrType::yellow,
                            bssType::bss812));
    lights.append(new light("BSS812X6m", &bss_inst.BSS812X6m, new bool{}, clrType::yellow,
                            bssType::bss812));
    lights.append(new light("BSS812X6q", &bss_inst.BSS812X6q, new bool{}, clrType::yellow,
                            bssType::bss812));
    lights.append(new light("OUT_D", &DEVICE_CONNECT.OUT_D[0][65], new bool{},
                            clrType::yellow, bssType::bss812));
    lights.append(new light("BSS812X5h", &bss_inst.BSS812X5h , &DEVICE_CONNECT.OUT_D[0][100],
                            clrType::red, bssType::bss812));
    lights.append(new light("BSS812X5n", &bss_inst.BSS812X5n , &DEVICE_CONNECT.OUT_D[0][101],
                            clrType::red, bssType::bss812));
    lights.append(new light("BSS812X6g", &bss_inst.BSS812X6g, new bool{},  clrType::red,
                            bssType::bss812));
    lights.append(new light("BSS812X6h", &bss_inst.BSS812X6h, new bool{}, clrType::red,
                            bssType::bss812));
    lights.append(new light("BSS812X6i", &bss_inst.BSS812X6i, new bool{}, clrType::red,
                            bssType::bss812));
    lights.append(new light("BSS812X5B", &bss_inst.BSS812X5B , (&bss_inst.BSS812X6A ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5D", &bss_inst.BSS812X5D , (&bss_inst.BSS812X6B ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5E", &bss_inst.BSS812X5E , &DEVICE_CONNECT.OUT_D[0][74],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5G", &bss_inst.BSS812X5G , &DEVICE_CONNECT.OUT_D[0][75],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5J", &bss_inst.BSS812X5J , &DEVICE_CONNECT.OUT_D[0][76],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5L", &bss_inst.BSS812X5L , &DEVICE_CONNECT.OUT_D[0][77],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5N", &bss_inst.BSS812X5N , &DEVICE_CONNECT.OUT_D[0][73],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5R", &bss_inst.BSS812X5R , (&bss_inst.BSS812X6H ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5T", &bss_inst.BSS812X5T , (&bss_inst.BSS812X6J ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5V", &bss_inst.BSS812X5V , (&bss_inst.BSS812X6K ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5X", &bss_inst.BSS812X5X , (&bss_inst.BSS812X6L ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5Z", &bss_inst.BSS812X5Z , (&bss_inst.BSS812X5b ),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5t", &bss_inst.BSS812X5t  , (&bss_inst.BSS812X6X),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5r", &bss_inst.BSS812X5r  , &DEVICE_CONNECT.OUT_D[0][69],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5z", &bss_inst.BSS812X5z  , (&bss_inst.BSS812X6a),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5BB", &bss_inst.BSS812X5BB  , (&bss_inst.BSS812X6b),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5DD", &bss_inst.BSS812X5DD  , (&bss_inst.BSS812X6c),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5FF", &bss_inst.BSS812X5FF  , (&bss_inst.BSS812X6d),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812_vkl_rt", &bss_inst.BSS812_vkl_rt, &DEVICE_CONNECT.OUT_D[0][66],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812_vkl_ft", &bss_inst.BSS812_vkl_ft  ,&DEVICE_CONNECT.OUT_D[0][67],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5KK", &bss_inst.BSS812X5KK  , (&bss_inst.BSS812X6f),
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS913X1C", &bss_inst.BSS913X1C, (&bss_inst.BSS913X2B),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1E", &bss_inst.BSS913X1E, (&bss_inst.BSS913X2C),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1G", &bss_inst.BSS913X1G, (&bss_inst.BSS913X2D),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1J", &bss_inst.BSS913X1J, (&bss_inst.BSS913X2E),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1L", &bss_inst.BSS913X1L, (&bss_inst.BSS913X2F),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1N", &bss_inst.BSS913X1N, (&bss_inst.BSS913X2G),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1T", &bss_inst.BSS913X1T, (&bss_inst.BSS913X2J),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1V", &bss_inst.BSS913X1V, (&bss_inst.BSS913X2K),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1X", &bss_inst.BSS913X1X, (&bss_inst.BSS913X2L),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1Z", &bss_inst.BSS913X1Z, (&bss_inst.BSS913X2M),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1b", &bss_inst.BSS913X1b, (&bss_inst.BSS913X2N),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1d", &bss_inst.BSS913X1d, (&bss_inst.BSS913X2P),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1h", &bss_inst.BSS913X1h, (&bss_inst.BSS913X2S),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1j", &bss_inst.BSS913X1j, (&bss_inst.BSS913X2T),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1n", &bss_inst.BSS913X1n, (&bss_inst.BSS913X2U),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1p", &bss_inst.BSS913X1p, (&bss_inst.BSS913X2V),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1r", &bss_inst.BSS913X1r, (&bss_inst.BSS913X2W),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1t", &bss_inst.BSS913X1t, (&bss_inst.BSS913X2X),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1x", &bss_inst.BSS913X1x, (&bss_inst.BSS913X2Z),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1z", &bss_inst.BSS913X1z, (&bss_inst.BSS913X2a),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1BB", &bss_inst.BSS913X1BB, (&bss_inst.BSS913X2b),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1DD", &bss_inst.BSS913X1DD, (&bss_inst.BSS913X2c),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1FF", &bss_inst.BSS913X1FF, (&bss_inst.BSS913X2d),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1HH", &bss_inst.BSS913X1HH, (&bss_inst.BSS913X2e),
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X3E", &bss_inst.BSS913X3E, &DEVICE_CONNECT.OUT_D[0][108],
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X3G", &bss_inst.BSS913X3G, &DEVICE_CONNECT.OUT_D[0][109],
                            clrType::yellow, bssType::bss913));
    lights.append(new light("BSS913X1A", &bss_inst.BSS913X1A, (&bss_inst.BSS913X2A),
                            clrType::red, bssType::bss913));
    lights.append(new light("BSS913X1R", &bss_inst.BSS913X1R, (&bss_inst.BSS913X2H),
                            clrType::red, bssType::bss913));
    lights.append(new light("BSS913X1f", &bss_inst.BSS913X1f, (&bss_inst.BSS913X2R),
                            clrType::red, bssType::bss913));
    lights.append(new light("BSS913X1v", &bss_inst.BSS913X1v, (&bss_inst.BSS913X2Y),
                            clrType::red, bssType::bss913));
    lights.append(new light("BSS913X3A", &bss_inst.BSS913X3A, (&bss_inst.BSS913X2h),
                            clrType::white, bssType::bss913));
    lights.append(new light("BSS913X3C", &bss_inst.BSS913X3C, &DEVICE_CONNECT.OUT_D[0][115],
                            clrType::white, bssType::bss913));
    lights.append(new light("BSS913X3J", &bss_inst.BSS913X3J, &DEVICE_CONNECT.OUT_D[0][112],
                            clrType::white, bssType::bss913));
    lights.append(new light("BSS913X3L", &bss_inst.BSS913X3L, &DEVICE_CONNECT.OUT_D[0][111],
                            clrType::white, bssType::bss913));
    lights.append(new light("BSS913X3N", &bss_inst.BSS913X3N, &DEVICE_CONNECT.OUT_D[0][110],
                            clrType::white, bssType::bss913));
    lights.append(new light("BSS824X1D", &bss_inst.BSS824X1D, &DEVICE_CONNECT.OUT_D[1][18],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1J", &bss_inst.BSS824X1J, &DEVICE_CONNECT.OUT_D[1][12],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1M", &bss_inst.BSS824X1M, (&bss_inst.BSS824X2F),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1N", &bss_inst.BSS824X1N, &DEVICE_CONNECT.OUT_D[1][6],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1T", &bss_inst.BSS824X1T, &DEVICE_CONNECT.OUT_D[1][4],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1V", &bss_inst.BSS824X1V, &DEVICE_CONNECT.OUT_D[1][4],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1b", &bss_inst.BSS824X1b, (&bss_inst.BSS824X2N),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1f", &bss_inst.BSS824X1f, &DEVICE_CONNECT.OUT_D[1][5],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1h", &bss_inst.BSS824X1h, (&bss_inst.BSS824X2S),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1j", &bss_inst.Pmalo, (&bss_inst.BSS824X2T),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1A", &bss_inst.BSS824X1A, (&bss_inst.BSS824X2A),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1n", &bss_inst.levOpShUbrno, &DEVICE_CONNECT.OUT_D[1][29],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1p", &bss_inst.perOpShUbrno, &DEVICE_CONNECT.OUT_D[1][31],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1r", &bss_inst.pravOpShUbrno, &DEVICE_CONNECT.OUT_D[1][33],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1t", &bss_inst.BSS824X1t, &DEVICE_CONNECT.OUT_D[1][27],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1v", &bss_inst.BSS824X1v, &DEVICE_CONNECT.OUT_D[1][26],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1x", &bss_inst.BSS824X1x, (&bss_inst.BSS824X2Z),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1z", &bss_inst.BSS824X1z, &DEVICE_CONNECT.OUT_D[1][45],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1BB", &bss_inst.BSS824X1BB, &DEVICE_CONNECT.OUT_D[1][46],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1DD", &bss_inst.BSS824X1DD, (&bss_inst.BSS824X2c),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1FF", &bss_inst.BSS824X1FF, &DEVICE_CONNECT.OUT_D[1][48],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1HH", &bss_inst.BSS824X1HH, &DEVICE_CONNECT.OUT_D[1][52],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X3L", &bss_inst.BSS824X3L, (&bss_inst.BSS824X2n),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X3T", &bss_inst.BSS824X3T, (&bss_inst.BSS824X2r),
                            clrType::yellow, bssType::bss824));
    lights.append(new light("BSS824X1X", &bss_inst.BSS824X1X, (&bss_inst.BSS824X2L),
                            clrType::red, bssType::bss824));
    lights.append(new light("BSS824X1Z", &bss_inst.BSS824X1Z, (&bss_inst.BSS824X2M),
                            clrType::red, bssType::bss824));
    lights.append(new light("BSS824X3G", &bss_inst.BSS824X3G, (&bss_inst.BSS824X2k),
                            clrType::red, bssType::bss824));
    lights.append(new light("BSS824X3J", &bss_inst.BSS824X3J, (&bss_inst.BSS824X2m),
                            clrType::red, bssType::bss824));
    lights.append(new light("BSS824X1R", &bss_inst.BSS824X1R, &DEVICE_CONNECT.OUT_D[1][7],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X1E", &bss_inst.BSS824X1E, &DEVICE_CONNECT.OUT_D[1][47],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X1KK", &bss_inst.BSS824X1KK, (&DEVICE_CONNECT.OUT_D[1][66]),
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X3N", &bss_inst.BSS824X3N, (&bss_inst.BSS824X2p),
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X3R", &bss_inst.BSS824X3R, (&bss_inst.BSS824X2q),
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X3E", &bss_inst.BSS824X3E, &DEVICE_CONNECT.OUT_D[1][49],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS825X5A", &bss_inst.BSS825X5A, (&bss_inst.BSS825X6A),
                            clrType::yellow, bssType::bss825));
    lights.append(new light("BSS825X5C", &bss_inst.BSS825X5C, (&bss_inst.BSS825X6B),
                            clrType::yellow, bssType::bss825));
    lights.append(new light("BSS825X5E", &bss_inst.BSS825X5E, (&bss_inst.BSS825X6C),
                            clrType::yellow, bssType::bss825));
    lights.append(new light("BSS825X5G", &bss_inst.BSS825X5G, (&bss_inst.BSS825X6D),
                            clrType::yellow, bssType::bss825));
    lights.append(new light("BSS825X5G", &bss_inst.BSS825X5G, (&bss_inst.BSS825X6D),
                            clrType::yellow, bssType::bss825));
    lights.append(new light("BSS825X6r", (&bss_inst.BSS825X6r), new bool{}, clrType::yellow,
                            bssType::bss825));
    lights.append(new light("BSS825X6m", (&bss_inst.BSS825X6m), new bool{}, clrType::yellow,
                            bssType::bss825));
    lights.append(new light("BSS825X6m", (&bss_inst.BSS825X6m), new bool{}, clrType::yellow,
                            bssType::bss825));
    lights.append(new light("BSS825X6n", (&bss_inst.BSS825X6n), new bool{}, clrType::yellow,
                            bssType::bss825));
    lights.append(new light("BSS825X6p", (&bss_inst.BSS825X6p), new bool{}, clrType::yellow,
                            bssType::bss825));
    lights.append(new light("BSS825X5L", &bss_inst.BSS825X5L, (&bss_inst.BSS825X6F),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5f", &bss_inst.BSS825X5f, (&bss_inst.BSS825X6R),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5N", &bss_inst.BSS825X5N, (&bss_inst.BSS825X6G),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5h", &bss_inst.BSS825X5h, (&bss_inst.BSS825X6S),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5R", &bss_inst.BSS825X5R, (&bss_inst.BSS825X6H),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5j", &bss_inst.BSS825X5j, (&bss_inst.BSS825X6T),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5T", &bss_inst.BSS825X5T, (&bss_inst.BSS825X6J),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X5n", &bss_inst.BSS825X5n, (&bss_inst.BSS825X6U),
                            clrType::red, bssType::bss825));
    lights.append(new light("BSS825X6i", (&bss_inst.BSS825X6i), new bool{}, clrType::red,
                            bssType::bss825));
    lights.append(new light("BSS825X6j", (&bss_inst.BSS825X6j), new bool{}, clrType::red,
                            bssType::bss825));
    lights.append(new light("BSS825X6k", (&bss_inst.BSS825X6k), new bool{}, clrType::red,
                            bssType::bss825));
    lights.append(new light("BSS825X5J", &bss_inst.BSS825X5J, (&bss_inst.BSS825X6E),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5V", &bss_inst.BSS825X5V, (&bss_inst.BSS825X6K),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5FF", &bss_inst.BSS825X5FF, (&bss_inst.BSS825X6d),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5HH", &bss_inst.BSS825X5HH, (&bss_inst.BSS825X6e),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5X", &bss_inst.BSS825X5X, (&bss_inst.BSS825X6L),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5Z", &bss_inst.BSS825X5Z, (&bss_inst.BSS825X6M),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5b", &bss_inst.BSS825X5b, (&bss_inst.BSS825X6N),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5d", &bss_inst.BSS825X5d, (&bss_inst.BSS825X6P),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5r", &bss_inst.BSS825X5r, (&bss_inst.BSS825X6W),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5t", &bss_inst.BSS825X5t, (&bss_inst.BSS825X6X),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X7R", &bss_inst.BSS825X7R, &DEVICE_CONNECT.OUT_D[1][50],
                            clrType::white, bssType::bss825));
//    lights.append(new light("BSS825X5v", &bss_inst.levOpShVipshno, &DEVICE_CONNECT.OUT_D[1][28],
//                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5x", &bss_inst.perOpShasVipno, &DEVICE_CONNECT.OUT_D[1][30],
                            clrType::white, bssType::bss825));
//    lights.append(new light("BSS825X5z", &bss_inst.pravOpShVipshno, &DEVICE_CONNECT.OUT_D[1][32],
//                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5z", &bss_inst.pravOpShVipshno, (&bss_inst.BSS825X6a),
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5KK", &bss_inst.BSS825X5KK, &DEVICE_CONNECT.OUT_D[1][53],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5MM", &bss_inst.BSS825X5MM, &DEVICE_CONNECT.OUT_D[1][54],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825PR", &bss_inst.BSS825X5p, &DEVICE_CONNECT.OUT_D[1][44],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS926X1C", &bss_inst.BSS926X1C, (&DEVICE_CONNECT.OUT_D[2][86]),
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1G", &bss_inst.BSS926X1G, &DEVICE_CONNECT.OUT_D[2][88],
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1d", &bss_inst.BSS926X1d, &DEVICE_CONNECT.OUT_D[2][106],
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X3V", &bss_inst.BSS926X3V, &DEVICE_CONNECT.OUT_D[2][115],
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1x", &bss_inst.otklyuchiG1L, (&DEVICE_CONNECT.OUT_D[2][12]),
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1BB", &bss_inst.BSS926X1BB, (&DEVICE_CONNECT.OUT_D[2][15]),
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1FF", &bss_inst.BSS926X1FF, (&DEVICE_CONNECT.OUT_D[2][17]),
                            clrType::yellow, bssType::bss926));
    lights.append(new light("BSS926X1A", &bss_inst.BSS926X1A, (&DEVICE_CONNECT.OUT_D[2][85]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1E", &bss_inst.BSS926X1E, (&DEVICE_CONNECT.OUT_D[2][87]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1J", &bss_inst.BSS926X1J, &DEVICE_CONNECT.OUT_D[2][89],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1L", &bss_inst.BSS926X1L, (&DEVICE_CONNECT.OUT_D[2][93]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1N", &bss_inst.BSS926X1N, (&DEVICE_CONNECT.OUT_D[2][94]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1R", &bss_inst.BSS926X1R, &DEVICE_CONNECT.OUT_D[2][104],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1T", &bss_inst.BSS926X1T, &DEVICE_CONNECT.OUT_D[2][105],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1V", &bss_inst.BSS926X1V, &DEVICE_CONNECT.OUT_D[2][114],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1X", &bss_inst.BSS926X1X, &DEVICE_CONNECT.OUT_D[2][113],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1Z", &bss_inst.BSS926X1Z, &DEVICE_CONNECT.OUT_D[2][122],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1b", &bss_inst.BSS926X1b, &DEVICE_CONNECT.OUT_D[2][123],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1f", &bss_inst.BSS926X1f, &DEVICE_CONNECT.OUT_D[2][80],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1h", &bss_inst.BSS926X1h, &DEVICE_CONNECT.OUT_D[2][81],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1j", &bss_inst.BSS926X1j, &DEVICE_CONNECT.OUT_D[2][82],
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1n", &bss_inst.BSS926X1n, (&bss_inst.BSS926X2U),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1t", &bss_inst.BSS926X1t, (&bss_inst.BSS926X2U),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1p", &bss_inst.BSS926X1p, (&bss_inst.BSS926X2V),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1r", &bss_inst.BSS926X1r, (&bss_inst.BSS926X2W),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1z", &bss_inst.BSS926X1z, (&DEVICE_CONNECT.OUT_D[2][13]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1DD", &bss_inst.BSS926X1DD, (&DEVICE_CONNECT.OUT_D[2][16]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1KK", &bss_inst.BSS926X1KK, (&bss_inst.BSS926X2f),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X1MM", &bss_inst.BSS926X1MM, (&DEVICE_CONNECT.OUT_D[2][11]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3A", &bss_inst.vklChRL, (&DEVICE_CONNECT.OUT_D[2][14]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3C", &bss_inst.BSS926X3C, (&DEVICE_CONNECT.OUT_D[2][27]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3E", &bss_inst.BSS926X3E, (&DEVICE_CONNECT.OUT_D[2][28]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3H", &bss_inst.BSS926X3H, (&bss_inst.BSS926X2k),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3J", &bss_inst.BSS926X3J, (&DEVICE_CONNECT.OUT_D[2][21]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3L", &bss_inst.BSS926X3L, (&DEVICE_CONNECT.OUT_D[2][24]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3N", &bss_inst.BSS926X3N, (&DEVICE_CONNECT.OUT_D[2][36]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3R", &bss_inst.BSS926X3R, (&DEVICE_CONNECT.OUT_D[2][54]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS926X3T", &bss_inst.BSS926X3T, (&DEVICE_CONNECT.OUT_D[2][55]),
                            clrType::white, bssType::bss926));
    lights.append(new light("BSS837X1A", &bss_inst.BSS837X1A, (&bss_inst.BSS837X2A),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1C", &bss_inst.BSS837X1C, (&bss_inst.BSS837X2B),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1E", &bss_inst.BSS837X1E, (&bss_inst.BSS837X2C),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1G", &bss_inst.BSS837X1G, (&bss_inst.BSS837X2D),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1J", &bss_inst.BSS837X1J, (&DEVICE_CONNECT.OUT_D[2][5]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1N", &bss_inst.BSS837X1N, (&DEVICE_CONNECT.OUT_D[2][9]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1R", &bss_inst.BSS837X1R, (&DEVICE_CONNECT.OUT_D[2][6]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1V", &bss_inst.BSS837X1V, (&DEVICE_CONNECT.OUT_D[2][10]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1L", &bss_inst.BSS837X1L, (&DEVICE_CONNECT.OUT_D[2][7]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1X", &bss_inst.BSS837X1X, &DEVICE_CONNECT.OUT_D[2][61],
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1Z", &bss_inst.BSS837X1Z, &DEVICE_CONNECT.OUT_D[2][62],
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1b", &bss_inst.BSS837X1b, (&DEVICE_CONNECT.OUT_D[2][30]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1d", &bss_inst.BSS837X1d, (&DEVICE_CONNECT.OUT_D[2][32]),
                            clrType::red, bssType::bss837));
    lights.append(new light("BSS837X1f", &bss_inst.BSS837X1f, (&DEVICE_CONNECT.OUT_D[2][31]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1h", &bss_inst.BSS837X1h, (&DEVICE_CONNECT.OUT_D[2][35]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1j", &bss_inst.BSS837X1j, (&DEVICE_CONNECT.OUT_D[2][25]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1r", &bss_inst.BSS837X1r, (&DEVICE_CONNECT.OUT_D[2][34]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1t", &bss_inst.BSS837X1t, (&DEVICE_CONNECT.OUT_D[2][22]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1x", &bss_inst.BSS837X1x, (&DEVICE_CONNECT.OUT_D[2][19]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1BB", &bss_inst.BSS837X1BB, (&DEVICE_CONNECT.OUT_D[2][57]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1DD", &bss_inst.BSS837X1DD, (&DEVICE_CONNECT.OUT_D[2][58]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1KK", &bss_inst.BSS837X1KK, (&DEVICE_CONNECT.OUT_D[2][60]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X3G", &bss_inst.BSS837X3G, (&DEVICE_CONNECT.OUT_D[2][59]),
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1p", &bss_inst.pravOtAkk, (&DEVICE_CONNECT.OUT_D[2][33]),
                            clrType::red, bssType::bss837));
    lights.append(new light("BSS837X3C", &bss_inst.BSS837X3C, (&DEVICE_CONNECT.OUT_D[2][50]),
                            clrType::red, bssType::bss837));
    lights.append(new light("BSS837X3N", &bss_inst.BSS837X3N, (&DEVICE_CONNECT.OUT_D[2][48]),
                            clrType::red, bssType::bss837));
    lights.append(new light("BSS837X1T", &bss_inst.BSS837X1T, (&bss_inst.BSS837X2J),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X1n", &bss_inst.BSS837X1n, (&DEVICE_CONNECT.OUT_D[2][26]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X1v", &bss_inst.BSS837X1v, (&DEVICE_CONNECT.OUT_D[2][23]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X1FF", &bss_inst.BSS837X1FF, (&DEVICE_CONNECT.OUT_D[2][56]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X1HH", &bss_inst.BSS837X1HH, (&DEVICE_CONNECT.OUT_D[2][45]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X3A", &bss_inst.BSS837X3A, (&DEVICE_CONNECT.OUT_D[2][53]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X3E", &bss_inst.BSS837X3E, (&DEVICE_CONNECT.OUT_D[2][51]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X3L", &bss_inst.BSS837X3L, (&DEVICE_CONNECT.OUT_D[2][47]),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS837X3R", &bss_inst.ppo3Otkl, (&DEVICE_CONNECT.OUT_D[2][49]),
                            clrType::red, bssType::bss837));
    lights.append(new light("BSS837X3T", &bss_inst.BSS837X3T, (&bss_inst.BSS837X2r),
                            clrType::white, bssType::bss837));
    lights.append(new light("BSS838X5T", &bss_inst.BSS838X5T, &DEVICE_CONNECT.OUT_D[2][90],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5V", &bss_inst.BSS838X5V, &DEVICE_CONNECT.OUT_D[2][91],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5Z", &bss_inst.BSS838X5Z, &DEVICE_CONNECT.OUT_D[2][95],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5d", &bss_inst.otklyuchiToGo, &DEVICE_CONNECT.OUT_D[2][98],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5h", &bss_inst.BSS838X5h, &DEVICE_CONNECT.OUT_D[2][102],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5n", &bss_inst.BSS838X5n, &DEVICE_CONNECT.OUT_D[2][100],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5p", &bss_inst.BSS838X5p, &bss_inst.BSS838X6V,
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5v", &bss_inst.BSS838X5v, &DEVICE_CONNECT.OUT_D[2][109],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5z", &bss_inst.BSS838X5z, &DEVICE_CONNECT.OUT_D[2][111],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5DD", &bss_inst.BSS838X5DD, &DEVICE_CONNECT.OUT_D[2][118],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5HH", &bss_inst.BSS838X5HH, &DEVICE_CONNECT.OUT_D[2][120],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X7E", &bss_inst.BSS838X7E, &bss_inst.BSS838X6j,
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X7J", &bss_inst.BSS838X7J, &bss_inst.BSS838X6m,
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X7R", &bss_inst.BSS838X7R, &DEVICE_CONNECT.OUT_D[2][108],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X7T", &bss_inst.BSS838X7T, &DEVICE_CONNECT.OUT_D[2][117],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5E", &bss_inst.BSS838X5E, &DEVICE_CONNECT.OUT_D[2][39],
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X5N", &bss_inst.BSS838X5N, &DEVICE_CONNECT.OUT_D[2][41],
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X7C", &bss_inst.BSS838X7C, &DEVICE_CONNECT.OUT_D[2][79],
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X7G", &bss_inst.BSS838X7G, &bss_inst.BSS838X6k,
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X7L", &bss_inst.BSS838X7L, &bss_inst.BSS838X6n,
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X7N", &bss_inst.vsuPohzar, &DEVICE_CONNECT.OUT_D[2][69],
                            clrType::red, bssType::bss838));
    lights.append(new light("BSS838X5C", &bss_inst.BSS838X5C, &DEVICE_CONNECT.OUT_D[2][38],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5G", &bss_inst.BSS838X5G, &DEVICE_CONNECT.OUT_D[2][40],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5L", &bss_inst.BSS838X5L, &DEVICE_CONNECT.OUT_D[2][44],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5R", &bss_inst.BSS838X5R, &DEVICE_CONNECT.OUT_D[2][42],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5X", &bss_inst.BSS838X5X, &DEVICE_CONNECT.OUT_D[2][92],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5b", &bss_inst.BSS838X5b, &DEVICE_CONNECT.OUT_D[2][96],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5f", &bss_inst.BSS838X5f, &DEVICE_CONNECT.OUT_D[2][99],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5j", &bss_inst.BSS838X5j, &DEVICE_CONNECT.OUT_D[2][103],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5x", &bss_inst.BSS838X5x, &DEVICE_CONNECT.OUT_D[2][110],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5BB", &bss_inst.BSS838X5BB, &DEVICE_CONNECT.OUT_D[2][112],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5FF", &bss_inst.BSS838X5FF, &DEVICE_CONNECT.OUT_D[2][119],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5KK", &bss_inst.BSS838X5KK, &DEVICE_CONNECT.OUT_D[2][121],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5r", &bss_inst.BSS838X5r, &DEVICE_CONNECT.OUT_D[2][97],
                            clrType::white, bssType::bss838));
    lights.append(new light("zakr_om1", &bss_inst.zakr_om1, &DEVICE_CONNECT.OUT_D[2][107],
                            clrType::white, bssType::bss838));
    lights.append(new light("zakr_om2", &bss_inst.zakr_om2, &DEVICE_CONNECT.OUT_D[2][116],
                            clrType::white, bssType::bss838));
    lights.append(new light("PONdv4", &antiicing.PONdv4, &DEVICE_CONNECT.OUT_D[0][1],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS812X5v", &bss_inst.BSS812X5v, &DEVICE_CONNECT.OUT_D[1][64],
                            clrType::white, bssType::bss812));
    lights.append(new light("BSS812X5x", &bss_inst.BSS812X5x, &DEVICE_CONNECT.OUT_D[1][64],
                            clrType::white, bssType::bss812));
    //blinking lights
    lights.append(new light("BSS811X1E", &bss_inst.BSS811X1E, &DEVICE_CONNECT.OUT_D[0][12],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X1G", &bss_inst.BSS824X1G, &DEVICE_CONNECT.OUT_D[1][1],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X1d", &bss_inst.BSS824X1d, &DEVICE_CONNECT.OUT_D[1][22],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X1MM", &bss_inst.BSS824X1MM, &DEVICE_CONNECT.OUT_D[1][66],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X3A", &bss_inst.BSS824X3A, &DEVICE_CONNECT.OUT_D[1][67],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS824X3C", &bss_inst.BSS824X3C, &DEVICE_CONNECT.OUT_D[1][67],
                            clrType::white, bssType::bss824));
    lights.append(new light("BSS325X7A", &bss_inst.BSS825X7A, &DEVICE_CONNECT.OUT_D[1][65],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5BB", &bss_inst.levOpShVipshno, &DEVICE_CONNECT.OUT_D[1][28],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5DD", &bss_inst.pravOpShVipshno, &DEVICE_CONNECT.OUT_D[1][32],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS825X5MM", &bss_inst.BSS825X5MM, &DEVICE_CONNECT.OUT_D[2][83],
                            clrType::white, bssType::bss825));
    lights.append(new light("BSS838X7A", &bss_inst.BSS838X7A, &DEVICE_CONNECT.OUT_D[2][84],
                            clrType::white, bssType::bss825));
    lights.append(new light("cso_ll_k", &cso_ll_k, &DEVICE_CONNECT.OUT_D[0][55],
                            clrType::red, bssType::bss812));
    lights.append(new light("cso_ll_zh", &cso_ll_zh, &DEVICE_CONNECT.OUT_D[0][56],
                            clrType::yellow, bssType::bss812));
    lights.append(new light("cso_pl_k", &cso_pl_k, &DEVICE_CONNECT.OUT_D[1][24],
                            clrType::red, bssType::bss824));
    lights.append(new light("cso_pl_zh", &cso_pl_zh, &DEVICE_CONNECT.OUT_D[1][25],
                            clrType::yellow, bssType::bss824));
    lights.append(new light("cso_sho_k", &cso_sho_k, &DEVICE_CONNECT.OUT_D[2][67],
                            clrType::red, bssType::bss837));
    lights.append(new light("cso_sho_zh", &cso_sho_zh, &DEVICE_CONNECT.OUT_D[2][68],
                            clrType::yellow, bssType::bss837));
    lights.append(new light("cso_shn_k", &cso_shn_k, &DEVICE_CONNECT.OUT_D[3][44],
                            clrType::red, bssType::bss939));
    lights.append(new light("cso_shn_zh", &cso_shn_zh, &DEVICE_CONNECT.OUT_D[3][45],
                            clrType::yellow, bssType::bss939));
    lights.append(new light("BSS838X5u", &bss_inst.BSS838X5u, &DEVICE_CONNECT.OUT_D[2][65],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS838X5u", &bss_inst.BSS838X5u, &DEVICE_CONNECT.OUT_D[2][66],
                            clrType::white, bssType::bss838));
    lights.append(new light("BSS939", new bool{}, &DEVICE_CONNECT.OUT_D[3][43],
                            clrType::white, bssType::bss939));
    lights.append(new light("BSS838X5A", &bss_inst.otklyuchiGen1, &DEVICE_CONNECT.OUT_D[2][37],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS838X5J", &bss_inst.otklyuchiGen2, &DEVICE_CONNECT.OUT_D[2][43],
                            clrType::yellow, bssType::bss838));
    lights.append(new light("BSS837X3J", &bss_inst.otklyuchiGen3, &DEVICE_CONNECT.OUT_D[2][46],
                            clrType::yellow, bssType::bss837));
    lights.append(new light("BSS837X1MM", &bss_inst.otklyuchiGen4, &DEVICE_CONNECT.OUT_D[2][52],
                            clrType::yellow, bssType::bss837));
}

void emergencyalarm_int::updateLogic()
{
    emergencyalarm_1();
}
bool emergencyalarm_int::light::fromLlPad()
{
    if(bss == bssType::bss811 || bss == bssType::bss812 || bss == bssType::bss913)
        return true;
    return false;
}
bool emergencyalarm_int::light::fromPlPad()
{
    if(bss == bssType::bss824 || bss == bssType::bss825)
        return true;
    return false;
}
bool emergencyalarm_int::light::fromShoPad()
{
    if(bss == bssType::bss837 || bss == bssType::bss838 || bss == bssType::bss926)
        return true;
    return false;
}
bool emergencyalarm_int::light::fromShnPad()
{
    if(bss == bssType::bss939)
        return true;
    return false;
}


bool emergencyalarm_int::light::powerCheck()
{
    if(bss == bssType::bss939 &&
        (exchange::ush2dpl >= 18.0 || exchange::ush2dpp >= 18.0)) return true;
    if(bss == bssType::bss811 &&
        (exchange::ush1dpl >= 18.0 || exchange::ush1dpp >= 18.0)) return true;
    if(bss == bssType::bss812 &&
        (exchange::ush2dpl >= 18.0 || exchange::ush2dpp >= 18.0)) return true;
    if(bss == bssType::bss913 &&
        (exchange::ush2dpl >= 18.0 || exchange::ush2dpp >= 18.0)) return true;
    if(bss == bssType::bss824 &&
        (exchange::ush1dpl >= 18.0 || exchange::ush1dpp >= 18.0)) return true;
    if(bss == bssType::bss825 &&
        (exchange::ush2dpl >= 18.0 || exchange::ush2dpp >= 18.0)) return true;
    if(bss == bssType::bss926 &&
        (exchange::ush2dpl >= 18.0 || exchange::ush2dpp >= 18.0)) return true;
    if(bss == bssType::bss837 &&
        (exchange::ush1dpl >= 18.0 || exchange::ush1dpp >= 18.0)) return true;
    if(bss == bssType::bss838 &&
        (exchange::ush1dpl >= 18.0 || exchange::ush1dpp >= 18.0)) return true;
    return false;
}

void emergencyalarm_int::light::lightFromBtn()
{
    if(fromLlPad())
    {
        if(exchange::s5_3364) *inClue = true;
    }
    if(fromPlPad())
    {
        if(exchange::s6_3364) *inClue = true;
    }
    if(fromShoPad())
    {
        if(exchange::s7_3364) *inClue = true;
    }
    if(fromShnPad())
    {
        if(exchange::s8_3364) *inClue = true;
    }
}
void emergencyalarm_int::light::lightUp()
{
    if(*inClue &&  !(*outClue) && isChecked)
        isChecked = false;
    if(isBlnkng)
    {
        if(*inClue)
            *outClue = lamp_blink();
    }
    else
    {
        *outClue = *inClue;
    }
}

void emergencyalarm_int::light::updCentrlLight(emergencyalarm_int& emergencyalarm)
{
    if(*outClue)
    {
        //left pilot cso toggling
        if(fromLlPad() && (inClue != &emergencyalarm.cso_ll_k))
        {
            if(color == clrType::red && !isChecked)
            {
                emergencyalarm.cso_ll_k = true;
            }
            if(exchange::s1_3364) isChecked = true;
        }
        if(fromLlPad() && (inClue != &emergencyalarm.cso_ll_zh))
        {
            if(color == clrType::yellow && !isChecked)
            {
                emergencyalarm.cso_ll_zh = true;
            }
            if(exchange::s1_3364) isChecked = true;
        }

        //right pilot cso toggling
        if(fromPlPad() && (inClue != &emergencyalarm.cso_pl_k))
        {
            if(color == clrType::red && !isChecked)
            {
                emergencyalarm.cso_pl_k = true;
            }
            if(exchange::s2_3364) isChecked = true;
        }
        if(fromPlPad() && (inClue != &emergencyalarm.cso_pl_zh))
        {
            if(color == clrType::yellow && !isChecked)
            {
                emergencyalarm.cso_pl_zh = true;
            }
            if(exchange::s2_3364) isChecked = true;
        }

        //operator cso toggling
        if(fromShoPad() && (inClue != &emergencyalarm.cso_sho_k))
        {
            if(color == clrType::red && !isChecked)
            {
                emergencyalarm.cso_sho_k = true;
            }
            if(exchange::s3_3364) isChecked = true;
        }
        if(fromShoPad() && (inClue != &emergencyalarm.cso_sho_zh))
        {
            if(color == clrType::yellow && !isChecked)
            {
                emergencyalarm.cso_sho_zh = true;
            }
            if(exchange::s3_3364) isChecked = true;
        }

        //navigator cso toggling
        if(fromShnPad() && (inClue != &emergencyalarm.cso_shn_k))
        {
            if(color == clrType::red && !isChecked)
            {
                emergencyalarm.cso_shn_k = true;
            }
            if(exchange::s4_3364) isChecked = true;
        }
        if(fromShoPad() && (inClue != &emergencyalarm.cso_shn_zh))
        {
            if(color == clrType::yellow && !isChecked)
            {
                emergencyalarm.cso_shn_zh = true;
            }
            if(exchange::s4_3364) isChecked = true;
        }
    }
}

bool emergencyalarm_int::light::lamp_blink()
{
    counter++;
    if((counter * TICK) < 100)
    {
        return false;
    }
    if(((counter * TICK)) >= 100)
    {
        if(((counter * TICK)) >= 400)
            counter = 0;
        return true;
    }
    return false;
}
