/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

#define NEG_INF 0xff800000
#define POS_INF 0x7f800000
#define BIT_MASK2 0x007fffff
#define OFFSET 0x3f000000
#define EXP_OFFSET 126


const int    CANONICAL_NAN_I   = 0x7fc00000;

const float  TWO_TO_M126_F     = 1.17549435e-38;
const float  LN2_F             = 6.93147200e-01;
const double LN2_D             = 6.93147180559945309e-01;

// For vector versions. sqrt(2.0) / 2.0
const float PARTITION_CONST_F = 7.07106770e-01;

// High precision vector log coefficients
const float A0 =  1.76584080e-01;
const float B0 = -2.70946354e-01;
const float C0 =  3.36388230e-01;
const float D0 = -4.99450624e-01;
const float E0 =  9.99966204e-01;

// Medium precision vector log coefficients
const float A1 =  1.19006775e-01;
const float B1 = -1.86680108e-01;
const float C1 =  2.04949871e-01;
const float D1 = -2.49096970e-01;
const float E1 =  3.33146155e-01;
const float F1 = -5.00011146e-01;
const float G1 =  1.00000095e+00;

// Low precision vector log coefficients
const float A2 = -1.01191141e-01;
const float B2 =  1.62281945e-01;
const float C2 = -1.72489181e-01;
const float D2 =  1.98992521e-01;
const float E2 = -2.49700040e-01;
const float F2 =  3.33351016e-01;
const float G2 = -5.00003636e-01;
const float H2 =  9.99999940e-01;

// Fast scalar log spline coefficients
const static float C_F[] = {3.27939957e-01, -4.99974310e-01, 1.00000000e+00, 0.00000000e+00,
    3.11274350e-01, -4.99261737e-01, 9.99989152e-01, 5.87647371e-08,
    2.97323048e-01, -4.97968256e-01, 9.99948740e-01, 4.84168027e-07,
    2.84245700e-01, -4.96138841e-01, 9.99863029e-01, 1.82906570e-06,
    2.71954209e-01, -4.93841320e-01, 9.99719501e-01, 4.82569976e-06,
    2.60361850e-01, -4.91130143e-01, 9.99507785e-01, 1.03459224e-05,
    2.49431357e-01, -4.88060683e-01, 9.99220133e-01, 1.93420528e-05,
    2.39108786e-01, -4.84677851e-01, 9.98850286e-01, 3.28320639e-05,
    2.29344249e-01, -4.81020004e-01, 9.98393238e-01, 5.18805937e-05,
    2.20097512e-01, -4.77122277e-01, 9.97845292e-01, 7.75707376e-05,
    2.11346835e-01, -4.73022938e-01, 9.97204900e-01, 1.10931687e-04,
    2.03063115e-01, -4.68754053e-01, 9.96471345e-01, 1.52963592e-04,
    1.95218831e-01, -4.64344382e-01, 9.95644808e-01, 2.04619821e-04,
    1.87752441e-01, -4.59797233e-01, 9.94721591e-01, 2.67114490e-04,
    1.80667043e-01, -4.55150068e-01, 9.93705273e-01, 3.41219333e-04,
    1.73897192e-01, -4.50391650e-01, 9.92590189e-01, 4.28345054e-04,
    1.67462990e-01, -4.45565224e-01, 9.91383195e-01, 5.28969918e-04,
    1.61430076e-01, -4.40758318e-01, 9.90106344e-01, 6.42046332e-04,
    1.55644313e-01, -4.35878724e-01, 9.88734186e-01, 7.70689861e-04,
    1.50103718e-01, -4.30945277e-01, 9.87269998e-01, 9.15553421e-04,
    1.44823059e-01, -4.25995439e-01, 9.85723197e-01, 1.07667211e-03,
    1.39795348e-01, -4.21046942e-01, 9.84099567e-01, 1.25428662e-03,
    1.35019258e-01, -4.16122377e-01, 9.82406795e-01, 1.44826248e-03,
    1.30465612e-01, -4.11214411e-01, 9.80643392e-01, 1.65947527e-03,
    1.26043543e-01, -4.06240195e-01, 9.78778183e-01, 1.89261232e-03,
    1.21891886e-01, -4.01375294e-01, 9.76877868e-01, 2.14006752e-03,
    1.17891401e-01, -3.96500468e-01, 9.74897623e-01, 2.40821438e-03,
    1.14057854e-01, -3.91649038e-01, 9.72850978e-01, 2.69603287e-03,
    1.10426009e-01, -3.86883646e-01, 9.70766604e-01, 2.99996138e-03,
    1.06906973e-01, -3.82100254e-01, 9.68599200e-01, 3.32732033e-03,
    8.28357756e-01, -2.66953975e-01, 1.04454434e+00, 3.08173872e-03,
    8.01320195e-01, -2.87853241e-01, 1.03915930e+00, 2.61920667e-03,
    7.79166341e-01, -3.04475784e-01, 1.03500187e+00, 2.27260566e-03,
    7.54211962e-01, -3.22615802e-01, 1.03060591e+00, 1.91747397e-03,
    7.31398523e-01, -3.38657677e-01, 1.02684581e+00, 1.62368978e-03,
    7.09579229e-01, -3.53483856e-01, 1.02348757e+00, 1.37012382e-03,
    6.88625813e-01, -3.67238134e-01, 1.02047777e+00, 1.15056406e-03,
    6.68553829e-01, -3.79941136e-01, 1.01779783e+00, 9.62091377e-04,
    6.49063766e-01, -3.91818643e-01, 1.01538491e+00, 7.98685418e-04,
    6.30564570e-01, -4.02659327e-01, 1.01326728e+00, 6.60797581e-04,
    6.12503529e-01, -4.12818938e-01, 1.01136208e+00, 5.41689107e-04,
    5.95342040e-01, -4.22070533e-01, 1.00969946e+00, 4.42084856e-04,
    5.78779876e-01, -4.30612564e-01, 1.00823081e+00, 3.57907353e-04,
    5.62706709e-01, -4.38525170e-01, 1.00693226e+00, 2.86865281e-04,
    5.47264338e-01, -4.45764244e-01, 1.00580096e+00, 2.27927478e-04,
    5.32420099e-01, -4.52374965e-01, 1.00481951e+00, 1.79352122e-04,
    5.18129170e-01, -4.58404809e-01, 1.00397134e+00, 1.39578318e-04,
    5.04322886e-01, -4.63906854e-01, 1.00324035e+00, 1.07200991e-04,
    4.90912288e-01, -4.68936235e-01, 1.00261152e+00, 8.09888588e-05,
    4.78074521e-01, -4.73449230e-01, 1.00208259e+00, 6.03211010e-05,
    4.65682894e-01, -4.77515578e-01, 1.00163770e+00, 4.40929216e-05,
    4.53651607e-01, -4.81181413e-01, 1.00126529e+00, 3.14788085e-05,
    4.42084223e-01, -4.84434575e-01, 1.00096023e+00, 2.19407684e-05,
    4.30873096e-01, -4.87324685e-01, 1.00071180e+00, 1.48199579e-05,
    4.20081139e-01, -4.89853799e-01, 1.00051415e+00, 9.66911375e-06,
    4.09621984e-01, -4.92060065e-01, 1.00035894e+00, 6.02756700e-06,
    3.99495274e-01, -4.93958682e-01, 1.00024021e+00, 3.55091925e-06,
    3.89691710e-01, -4.95566547e-01, 1.00015223e+00, 1.94496329e-06,
    3.80235463e-01, -4.96895701e-01, 1.00008988e+00, 9.69014650e-07,
    3.71042609e-01, -4.97972071e-01, 1.00004780e+00, 4.19706623e-07,
    3.62167388e-01, -4.98802811e-01, 1.00002182e+00, 1.48014678e-07,
    3.53552163e-01, -4.99406904e-01, 1.00000763e+00, 3.64556492e-08,
    3.45275283e-01, -4.99793470e-01, 1.00000155e+00, 4.26518998e-09,
    3.36086333e-01, -4.99993742e-01, 1.00000000e+00, 0.00000000e+00};

// Precise scalar log spline coefficients
const static double C_D[] = {-2.43862104337742747e-01, 3.33273749766618832e-01, -4.99999814335061965e-01, 9.99999999909482629e-01,
        -2.32140847457631583e-01, 3.32727046140628091e-01, -4.99990956967389988e-01, 9.99999950277558058e-01,
        -2.21142491044019229e-01, 3.31698473969756213e-01, -4.99958557238069146e-01, 9.99999606612379632e-01,
        -2.10812799940731849e-01, 3.30248196691501905e-01, -4.99890369665313139e-01, 9.99998533043130911e-01,
        -2.01102315720543601e-01, 3.28429644698807532e-01, -4.99776549002215631e-01, 9.99996152250624659e-01,
        -1.91965875174040318e-01, 3.26290298334347639e-01, -4.99609290478337242e-01, 9.99991786121681936e-01,
        -1.83362183285553454e-01, 3.23872373329101126e-01, -4.99382522082639724e-01, 9.99984688658273058e-01,
        -1.75253433899071165e-01, 3.21213421782288122e-01, -4.99091641172082379e-01, 9.99974072486863763e-01,
        -1.67604972180046663e-01, 3.18346859888350764e-01, -4.98733288886638093e-01, 9.99959130081884862e-01,
        -1.60384993772208079e-01, 3.15302432016821732e-01, -4.98305156852434095e-01, 9.99939050626419856e-01,
        -1.53564276234960273e-01, 3.12106619398623553e-01, -4.97805821494323952e-01, 9.99913033275695140e-01,
        -1.47115938917612654e-01, 3.08783000517675987e-01, -4.97234601983668256e-01, 9.99880297458696887e-01,
        -1.41015227947155375e-01, 3.05352569338063429e-01, -4.96591438442119060e-01, 9.99840090745499288e-01,
        -1.35239323404819090e-01, 3.01834016649128567e-01, -4.95876787520615536e-01, 9.99791694718405455e-01,
        -1.29767166168641451e-01, 2.98243979114715174e-01, -4.95091532898394027e-01, 9.99734429210981657e-01,
        -1.24579302185865104e-01, 2.94597259986434434e-01, -4.94236908601751679e-01, 9.99667655217262530e-01,
        -1.19657742242278875e-01, 2.90907024934310920e-01, -4.93314433348859660e-01, 9.99590776722361407e-01,
        -1.14985835510176798e-01, 2.87184975984895230e-01, -4.92325854381672257e-01, 9.99503241662867303e-01,
        -1.10548155379641841e-01, 2.83441506181086156e-01, -4.91273099467358809e-01, 9.99404542190043599e-01,
        -1.06330396248469503e-01, 2.79685837239221857e-01, -4.90158235937151521e-01, 9.99294214379152335e-01,
        -1.02319280099944343e-01, 2.75926142188369639e-01, -4.88983435788570453e-01, 9.99171837503405991e-01,
        -9.85024718482827993e-02, 2.72169654740936684e-01, -4.87750946016803189e-01, 9.99037032970826466e-01,
        -9.48685025309697061e-02, 2.68422766911386668e-01, -4.86463063452482802e-01, 9.98889463004641764e-01,
        -9.14066995436607910e-02, 2.64691116223150280e-01, -4.85122113485517370e-01, 9.98728829133761375e-01,
        -8.81071232028492191e-02, 2.60979663680597385e-01, -4.83730432140019484e-01, 9.98554870547924911e-01,
        -8.49605089967580412e-02, 2.57292763536595137e-01, -4.82290351036973486e-01, 9.98367362361934352e-01,
        -8.19582149610595251e-02, 2.53634225769062693e-01, -4.80804184846426175e-01, 9.98166113825305401e-01,
        -7.90921736735827607e-02, 2.50007372067870215e-01, -4.79274220883621371e-01, 9.97950966506552906e-01,
        -7.63548484169335184e-02, 2.46415086039368875e-01, -4.77702710550035659e-01, 9.97721792475514180e-01,
        -7.37391931093530767e-02, 2.42859858257562233e-01, -4.76091862362126028e-01, 9.97478492502524516e-01,
        -7.12386156431013551e-02, 2.39343826714682101e-01, -4.74443836343719172e-01, 9.97220994289062523e-01,
        -6.88469443083946087e-02, 2.35868813161778129e-01, -4.72760739588302226e-01, 9.96949250741205106e-01,
        -6.14797232960107576e-01, 1.72727341250108468e-01, -5.28781944959972328e-01, 9.98131137955135528e-01,
        -5.95020381471787485e-01, 1.87097996262487742e-01, -5.25301028963141792e-01, 9.98412203805793430e-01,
        -5.76065941938505466e-01, 2.00426794217198723e-01, -5.22176605678820516e-01, 9.98656348663729099e-01,
        -5.57892048030716015e-01, 2.12780746453184955e-01, -5.19377211206999978e-01, 9.98867805888238425e-01,
        -5.40459349617747109e-01, 2.24222268996791180e-01, -5.16873957653630201e-01, 9.99050375153903714e-01,
        -5.23730838789888020e-01, 2.34809528576621879e-01, -5.14640316522481434e-01, 9.99207464517860577e-01,
        -5.07671689428181305e-01, 2.44596759992726176e-01, -5.12651921443382119e-01, 9.99342128357062709e-01,
        -4.92249109189307643e-01, 2.53634557408670303e-01, -5.10886388392337465e-01, 9.99457101597789332e-01,
        -4.77432202823997454e-01, 2.61970141921195609e-01, -5.09323151739461188e-01, 9.99554830614747369e-01,
        -4.63191845866936847e-01, 2.69647607519959143e-01, -5.07943314633029996e-01, 9.99637501136452222e-01,
        -4.49500567817131769e-01, 2.76708147350239464e-01, -5.06729512377816049e-01, 9.99707063457791145e-01,
        -4.36332444030971822e-01, 2.83190261996232651e-01, -5.05665787602485595e-01, 9.99765255228738936e-01,
        -4.23662995569901557e-01, 2.89129951365504456e-01, -5.04737476126248752e-01, 9.99813622060210738e-01,
        -4.11469096413404622e-01, 2.94560891555864512e-01, -5.03931102550933319e-01, 9.99853536162431444e-01,
        -3.99728887357667262e-01, 2.99514598027260326e-01, -5.03234284688465427e-01, 9.99886213209517871e-01,
        -3.88421696128676608e-01, 3.04020576206544990e-01, -5.02635646031975081e-01, 9.99912727603393003e-01,
        -3.77527963183646120e-01, 3.08106460596643428e-01, -5.02124735547405998e-01, 9.99934026292859102e-01,
        -3.67029172729078590e-01, 3.11798143355720814e-01, -5.01691954133595241e-01, 9.99950941287693018e-01,
        -3.56907788606545595e-01, 3.15119893194611311e-01, -5.01328487164389380e-01, 9.99964200993350150e-01,
        -3.47147194588926455e-01, 3.18094465416431549e-01, -5.01026242575238756e-01, 9.99974440479517224e-01,
        -3.37731638819207203e-01, 3.20743203793900644e-01, -5.00777794013830047e-01, 9.99982210784168046e-01,
        -3.28646182014960542e-01, 3.23086134964227500e-01, -5.00576328613675625e-01, 9.99987987344891249e-01,
        -3.19876649204010488e-01, 3.25142055926094631e-01, -5.00415598994228272e-01, 9.99992177640054103e-01,
        -3.11409584675700069e-01, 3.26928615201914630e-01, -5.00289879124554249e-01, 9.99995128114355203e-01,
        -3.03232209949270193e-01, 3.28462388154750040e-01, -5.00193923723016742e-01, 9.99997130455963501e-01,
        -2.95332384511116430e-01, 3.29758946925070573e-01, -5.00122930893496354e-01, 9.99998427285958336e-01,
        -2.87698569124842374e-01, 3.30832925404203892e-01, -5.00072507726401549e-01, 9.99999217314891720e-01,
        -2.80319791525659889e-01, 3.31698079628433506e-01, -5.00038638616792652e-01, 9.99999660016026914e-01,
        -2.73185614330459958e-01, 3.32367343944935112e-01, -5.00017656073968420e-01, 9.99999879860062446e-01,
        -2.66286104993563921e-01, 3.32852883272991285e-01, -5.00006213816727940e-01, 9.99999970151881690e-01,
        -2.59611807678746198e-01, 3.33166141754356160e-01, -5.00001261966663391e-01, 9.99999996506022115e-01,
        -2.53153716095682102e-01, 3.33317888076742064e-01, -5.00000024168037904e-01, 9.99999999994095057e-01};
