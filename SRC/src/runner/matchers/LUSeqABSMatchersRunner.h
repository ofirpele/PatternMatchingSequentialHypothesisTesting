#ifndef LU_SEQABSMATCHERSRUNNER_H_
#define LU_SEQABSMATCHERSRUNNER_H_

#include <isSimilar/DiffAbs_IsSimilar_uchar.h>

class LUSeqABSMatchersRunner {

private:
    
    int _thresh;
    
    typedef DiffAbs_IsSimilar_uchar<0> T_TABS0;
typedef LUSeqFastMatcher<T_TABS0,false> T_ABS0;
T_ABS0* _sfmABS0Ptr;
typedef DiffAbs_IsSimilar_uchar<1> T_TABS1;
typedef LUSeqFastMatcher<T_TABS1,false> T_ABS1;
T_ABS1* _sfmABS1Ptr;
typedef DiffAbs_IsSimilar_uchar<2> T_TABS2;
typedef LUSeqFastMatcher<T_TABS2,false> T_ABS2;
T_ABS2* _sfmABS2Ptr;
typedef DiffAbs_IsSimilar_uchar<3> T_TABS3;
typedef LUSeqFastMatcher<T_TABS3,false> T_ABS3;
T_ABS3* _sfmABS3Ptr;
typedef DiffAbs_IsSimilar_uchar<4> T_TABS4;
typedef LUSeqFastMatcher<T_TABS4,false> T_ABS4;
T_ABS4* _sfmABS4Ptr;
typedef DiffAbs_IsSimilar_uchar<5> T_TABS5;
typedef LUSeqFastMatcher<T_TABS5,false> T_ABS5;
T_ABS5* _sfmABS5Ptr;
typedef DiffAbs_IsSimilar_uchar<6> T_TABS6;
typedef LUSeqFastMatcher<T_TABS6,false> T_ABS6;
T_ABS6* _sfmABS6Ptr;
typedef DiffAbs_IsSimilar_uchar<7> T_TABS7;
typedef LUSeqFastMatcher<T_TABS7,false> T_ABS7;
T_ABS7* _sfmABS7Ptr;
typedef DiffAbs_IsSimilar_uchar<8> T_TABS8;
typedef LUSeqFastMatcher<T_TABS8,false> T_ABS8;
T_ABS8* _sfmABS8Ptr;
typedef DiffAbs_IsSimilar_uchar<9> T_TABS9;
typedef LUSeqFastMatcher<T_TABS9,false> T_ABS9;
T_ABS9* _sfmABS9Ptr;
typedef DiffAbs_IsSimilar_uchar<10> T_TABS10;
typedef LUSeqFastMatcher<T_TABS10,false> T_ABS10;
T_ABS10* _sfmABS10Ptr;
typedef DiffAbs_IsSimilar_uchar<11> T_TABS11;
typedef LUSeqFastMatcher<T_TABS11,false> T_ABS11;
T_ABS11* _sfmABS11Ptr;
typedef DiffAbs_IsSimilar_uchar<12> T_TABS12;
typedef LUSeqFastMatcher<T_TABS12,false> T_ABS12;
T_ABS12* _sfmABS12Ptr;
typedef DiffAbs_IsSimilar_uchar<13> T_TABS13;
typedef LUSeqFastMatcher<T_TABS13,false> T_ABS13;
T_ABS13* _sfmABS13Ptr;
typedef DiffAbs_IsSimilar_uchar<14> T_TABS14;
typedef LUSeqFastMatcher<T_TABS14,false> T_ABS14;
T_ABS14* _sfmABS14Ptr;
typedef DiffAbs_IsSimilar_uchar<15> T_TABS15;
typedef LUSeqFastMatcher<T_TABS15,false> T_ABS15;
T_ABS15* _sfmABS15Ptr;
typedef DiffAbs_IsSimilar_uchar<16> T_TABS16;
typedef LUSeqFastMatcher<T_TABS16,false> T_ABS16;
T_ABS16* _sfmABS16Ptr;
typedef DiffAbs_IsSimilar_uchar<17> T_TABS17;
typedef LUSeqFastMatcher<T_TABS17,false> T_ABS17;
T_ABS17* _sfmABS17Ptr;
typedef DiffAbs_IsSimilar_uchar<18> T_TABS18;
typedef LUSeqFastMatcher<T_TABS18,false> T_ABS18;
T_ABS18* _sfmABS18Ptr;
typedef DiffAbs_IsSimilar_uchar<19> T_TABS19;
typedef LUSeqFastMatcher<T_TABS19,false> T_ABS19;
T_ABS19* _sfmABS19Ptr;
typedef DiffAbs_IsSimilar_uchar<20> T_TABS20;
typedef LUSeqFastMatcher<T_TABS20,false> T_ABS20;
T_ABS20* _sfmABS20Ptr;
typedef DiffAbs_IsSimilar_uchar<21> T_TABS21;
typedef LUSeqFastMatcher<T_TABS21,false> T_ABS21;
T_ABS21* _sfmABS21Ptr;
typedef DiffAbs_IsSimilar_uchar<22> T_TABS22;
typedef LUSeqFastMatcher<T_TABS22,false> T_ABS22;
T_ABS22* _sfmABS22Ptr;
typedef DiffAbs_IsSimilar_uchar<23> T_TABS23;
typedef LUSeqFastMatcher<T_TABS23,false> T_ABS23;
T_ABS23* _sfmABS23Ptr;
typedef DiffAbs_IsSimilar_uchar<24> T_TABS24;
typedef LUSeqFastMatcher<T_TABS24,false> T_ABS24;
T_ABS24* _sfmABS24Ptr;
typedef DiffAbs_IsSimilar_uchar<25> T_TABS25;
typedef LUSeqFastMatcher<T_TABS25,false> T_ABS25;
T_ABS25* _sfmABS25Ptr;
typedef DiffAbs_IsSimilar_uchar<26> T_TABS26;
typedef LUSeqFastMatcher<T_TABS26,false> T_ABS26;
T_ABS26* _sfmABS26Ptr;
typedef DiffAbs_IsSimilar_uchar<27> T_TABS27;
typedef LUSeqFastMatcher<T_TABS27,false> T_ABS27;
T_ABS27* _sfmABS27Ptr;
typedef DiffAbs_IsSimilar_uchar<28> T_TABS28;
typedef LUSeqFastMatcher<T_TABS28,false> T_ABS28;
T_ABS28* _sfmABS28Ptr;
typedef DiffAbs_IsSimilar_uchar<29> T_TABS29;
typedef LUSeqFastMatcher<T_TABS29,false> T_ABS29;
T_ABS29* _sfmABS29Ptr;
typedef DiffAbs_IsSimilar_uchar<30> T_TABS30;
typedef LUSeqFastMatcher<T_TABS30,false> T_ABS30;
T_ABS30* _sfmABS30Ptr;
typedef DiffAbs_IsSimilar_uchar<31> T_TABS31;
typedef LUSeqFastMatcher<T_TABS31,false> T_ABS31;
T_ABS31* _sfmABS31Ptr;
typedef DiffAbs_IsSimilar_uchar<32> T_TABS32;
typedef LUSeqFastMatcher<T_TABS32,false> T_ABS32;
T_ABS32* _sfmABS32Ptr;
typedef DiffAbs_IsSimilar_uchar<33> T_TABS33;
typedef LUSeqFastMatcher<T_TABS33,false> T_ABS33;
T_ABS33* _sfmABS33Ptr;
typedef DiffAbs_IsSimilar_uchar<34> T_TABS34;
typedef LUSeqFastMatcher<T_TABS34,false> T_ABS34;
T_ABS34* _sfmABS34Ptr;
typedef DiffAbs_IsSimilar_uchar<35> T_TABS35;
typedef LUSeqFastMatcher<T_TABS35,false> T_ABS35;
T_ABS35* _sfmABS35Ptr;
typedef DiffAbs_IsSimilar_uchar<36> T_TABS36;
typedef LUSeqFastMatcher<T_TABS36,false> T_ABS36;
T_ABS36* _sfmABS36Ptr;
typedef DiffAbs_IsSimilar_uchar<37> T_TABS37;
typedef LUSeqFastMatcher<T_TABS37,false> T_ABS37;
T_ABS37* _sfmABS37Ptr;
typedef DiffAbs_IsSimilar_uchar<38> T_TABS38;
typedef LUSeqFastMatcher<T_TABS38,false> T_ABS38;
T_ABS38* _sfmABS38Ptr;
typedef DiffAbs_IsSimilar_uchar<39> T_TABS39;
typedef LUSeqFastMatcher<T_TABS39,false> T_ABS39;
T_ABS39* _sfmABS39Ptr;
typedef DiffAbs_IsSimilar_uchar<40> T_TABS40;
typedef LUSeqFastMatcher<T_TABS40,false> T_ABS40;
T_ABS40* _sfmABS40Ptr;
typedef DiffAbs_IsSimilar_uchar<41> T_TABS41;
typedef LUSeqFastMatcher<T_TABS41,false> T_ABS41;
T_ABS41* _sfmABS41Ptr;
typedef DiffAbs_IsSimilar_uchar<42> T_TABS42;
typedef LUSeqFastMatcher<T_TABS42,false> T_ABS42;
T_ABS42* _sfmABS42Ptr;
typedef DiffAbs_IsSimilar_uchar<43> T_TABS43;
typedef LUSeqFastMatcher<T_TABS43,false> T_ABS43;
T_ABS43* _sfmABS43Ptr;
typedef DiffAbs_IsSimilar_uchar<44> T_TABS44;
typedef LUSeqFastMatcher<T_TABS44,false> T_ABS44;
T_ABS44* _sfmABS44Ptr;
typedef DiffAbs_IsSimilar_uchar<45> T_TABS45;
typedef LUSeqFastMatcher<T_TABS45,false> T_ABS45;
T_ABS45* _sfmABS45Ptr;
typedef DiffAbs_IsSimilar_uchar<46> T_TABS46;
typedef LUSeqFastMatcher<T_TABS46,false> T_ABS46;
T_ABS46* _sfmABS46Ptr;
typedef DiffAbs_IsSimilar_uchar<47> T_TABS47;
typedef LUSeqFastMatcher<T_TABS47,false> T_ABS47;
T_ABS47* _sfmABS47Ptr;
typedef DiffAbs_IsSimilar_uchar<48> T_TABS48;
typedef LUSeqFastMatcher<T_TABS48,false> T_ABS48;
T_ABS48* _sfmABS48Ptr;
typedef DiffAbs_IsSimilar_uchar<49> T_TABS49;
typedef LUSeqFastMatcher<T_TABS49,false> T_ABS49;
T_ABS49* _sfmABS49Ptr;
typedef DiffAbs_IsSimilar_uchar<50> T_TABS50;
typedef LUSeqFastMatcher<T_TABS50,false> T_ABS50;
T_ABS50* _sfmABS50Ptr;
typedef DiffAbs_IsSimilar_uchar<100> T_TABS100;
typedef LUSeqFastMatcher<T_TABS100,false> T_ABS100;
T_ABS100* _sfmABS100Ptr;
    
    
public:    
            
    LUSeqABSMatchersRunner() 
        : 
        _sfmABS0Ptr(NULL),
_sfmABS1Ptr(NULL),
_sfmABS2Ptr(NULL),
_sfmABS3Ptr(NULL),
_sfmABS4Ptr(NULL),
_sfmABS5Ptr(NULL),
_sfmABS6Ptr(NULL),
_sfmABS7Ptr(NULL),
_sfmABS8Ptr(NULL),
_sfmABS9Ptr(NULL),
_sfmABS10Ptr(NULL),
_sfmABS11Ptr(NULL),
_sfmABS12Ptr(NULL),
_sfmABS13Ptr(NULL),
_sfmABS14Ptr(NULL),
_sfmABS15Ptr(NULL),
_sfmABS16Ptr(NULL),
_sfmABS17Ptr(NULL),
_sfmABS18Ptr(NULL),
_sfmABS19Ptr(NULL),
_sfmABS20Ptr(NULL),
_sfmABS21Ptr(NULL),
_sfmABS22Ptr(NULL),
_sfmABS23Ptr(NULL),
_sfmABS24Ptr(NULL),
_sfmABS25Ptr(NULL),
_sfmABS26Ptr(NULL),
_sfmABS27Ptr(NULL),
_sfmABS28Ptr(NULL),
_sfmABS29Ptr(NULL),
_sfmABS30Ptr(NULL),
_sfmABS31Ptr(NULL),
_sfmABS32Ptr(NULL),
_sfmABS33Ptr(NULL),
_sfmABS34Ptr(NULL),
_sfmABS35Ptr(NULL),
_sfmABS36Ptr(NULL),
_sfmABS37Ptr(NULL),
_sfmABS38Ptr(NULL),
_sfmABS39Ptr(NULL),
_sfmABS40Ptr(NULL),
_sfmABS41Ptr(NULL),
_sfmABS42Ptr(NULL),
_sfmABS43Ptr(NULL),
_sfmABS44Ptr(NULL),
_sfmABS45Ptr(NULL),
_sfmABS46Ptr(NULL),
_sfmABS47Ptr(NULL),
_sfmABS48Ptr(NULL),
_sfmABS49Ptr(NULL),
_sfmABS50Ptr(NULL),
_sfmABS100Ptr(NULL)
            {}
    
    ~LUSeqABSMatchersRunner() {
        delete _sfmABS0Ptr;
        delete _sfmABS1Ptr;
        delete _sfmABS2Ptr;
        delete _sfmABS3Ptr;
        delete _sfmABS4Ptr;
        delete _sfmABS5Ptr;
        delete _sfmABS6Ptr;
        delete _sfmABS7Ptr;
        delete _sfmABS8Ptr;
        delete _sfmABS9Ptr;
        delete _sfmABS10Ptr;
        delete _sfmABS11Ptr;
        delete _sfmABS12Ptr;
        delete _sfmABS13Ptr;
        delete _sfmABS14Ptr;
        delete _sfmABS15Ptr;
        delete _sfmABS16Ptr;
        delete _sfmABS17Ptr;
        delete _sfmABS18Ptr;
        delete _sfmABS19Ptr;
        delete _sfmABS20Ptr;
        delete _sfmABS21Ptr;
        delete _sfmABS22Ptr;
        delete _sfmABS23Ptr;
        delete _sfmABS24Ptr;
        delete _sfmABS25Ptr;
        delete _sfmABS26Ptr;
        delete _sfmABS27Ptr;
        delete _sfmABS28Ptr;
        delete _sfmABS29Ptr;
        delete _sfmABS30Ptr;
        delete _sfmABS31Ptr;
        delete _sfmABS32Ptr;
        delete _sfmABS33Ptr;
        delete _sfmABS34Ptr;
        delete _sfmABS35Ptr;
        delete _sfmABS36Ptr;
        delete _sfmABS37Ptr;
        delete _sfmABS38Ptr;
        delete _sfmABS39Ptr;
        delete _sfmABS40Ptr;
        delete _sfmABS41Ptr;
        delete _sfmABS42Ptr;
        delete _sfmABS43Ptr;
        delete _sfmABS44Ptr;
        delete _sfmABS45Ptr;
        delete _sfmABS46Ptr;
        delete _sfmABS47Ptr;
        delete _sfmABS48Ptr;
        delete _sfmABS49Ptr;
        delete _sfmABS50Ptr;
        delete _sfmABS100Ptr;
    }  
    
    void init(int thresh,
              
              int imWidthStep, int imWidth, int imHeight, 
              IplImage* pattern, 
              std::vector< Point > maskPixels,
              const double& falseNegative, 
              const double& maxOcclusion,
              
              std::vector< Point >& LUmaskPixels,
              const double& LUfalseNegative,
              const double& LUmaxOcclusion,
              const int& LUX,
              const int& LUY)
        {
        _thresh= thresh;
                
        switch (thresh) {
        case 0:
            _sfmABS0Ptr= new T_ABS0(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 1:
            _sfmABS1Ptr= new T_ABS1(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 2:
            _sfmABS2Ptr= new T_ABS2(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 3:
            _sfmABS3Ptr= new T_ABS3(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 4:
            _sfmABS4Ptr= new T_ABS4(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 5:
            _sfmABS5Ptr= new T_ABS5(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 6:
            _sfmABS6Ptr= new T_ABS6(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 7:
            _sfmABS7Ptr= new T_ABS7(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 8:
            _sfmABS8Ptr= new T_ABS8(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 9:
            _sfmABS9Ptr= new T_ABS9(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 10:
            _sfmABS10Ptr= new T_ABS10(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 11:
            _sfmABS11Ptr= new T_ABS11(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 12:
            _sfmABS12Ptr= new T_ABS12(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 13:
            _sfmABS13Ptr= new T_ABS13(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 14:
            _sfmABS14Ptr= new T_ABS14(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 15:
            _sfmABS15Ptr= new T_ABS15(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 16:
            _sfmABS16Ptr= new T_ABS16(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 17:
            _sfmABS17Ptr= new T_ABS17(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 18:
            _sfmABS18Ptr= new T_ABS18(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 19:
            _sfmABS19Ptr= new T_ABS19(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 20:
            _sfmABS20Ptr= new T_ABS20(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 21:
            _sfmABS21Ptr= new T_ABS21(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 22:
            _sfmABS22Ptr= new T_ABS22(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 23:
            _sfmABS23Ptr= new T_ABS23(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 24:
            _sfmABS24Ptr= new T_ABS24(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 25:
            _sfmABS25Ptr= new T_ABS25(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 26:
            _sfmABS26Ptr= new T_ABS26(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 27:
            _sfmABS27Ptr= new T_ABS27(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 28:
            _sfmABS28Ptr= new T_ABS28(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 29:
            _sfmABS29Ptr= new T_ABS29(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 30:
            _sfmABS30Ptr= new T_ABS30(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 31:
            _sfmABS31Ptr= new T_ABS31(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 32:
            _sfmABS32Ptr= new T_ABS32(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 33:
            _sfmABS33Ptr= new T_ABS33(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 34:
            _sfmABS34Ptr= new T_ABS34(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 35:
            _sfmABS35Ptr= new T_ABS35(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 36:
            _sfmABS36Ptr= new T_ABS36(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 37:
            _sfmABS37Ptr= new T_ABS37(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 38:
            _sfmABS38Ptr= new T_ABS38(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 39:
            _sfmABS39Ptr= new T_ABS39(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 40:
            _sfmABS40Ptr= new T_ABS40(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 41:
            _sfmABS41Ptr= new T_ABS41(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 42:
            _sfmABS42Ptr= new T_ABS42(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 43:
            _sfmABS43Ptr= new T_ABS43(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 44:
            _sfmABS44Ptr= new T_ABS44(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 45:
            _sfmABS45Ptr= new T_ABS45(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 46:
            _sfmABS46Ptr= new T_ABS46(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 47:
            _sfmABS47Ptr= new T_ABS47(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 48:
            _sfmABS48Ptr= new T_ABS48(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 49:
            _sfmABS49Ptr= new T_ABS49(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 50:
            _sfmABS50Ptr= new T_ABS50(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 100:
            _sfmABS100Ptr= new T_ABS100(imWidthStep, imWidth, imHeight,pattern,maskPixels, falseNegative, maxOcclusion,LUmaskPixels,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
            
        default:
            // Should never get here
            assert(false);
            
        } // end switch
        
    } // end init
    
    
    void match(IplImage* image, CvMat* result) {
        switch (_thresh) {
        case 0:
            _sfmABS0Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 1:
            _sfmABS1Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 2:
            _sfmABS2Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 3:
            _sfmABS3Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 4:
            _sfmABS4Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 5:
            _sfmABS5Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 6:
            _sfmABS6Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 7:
            _sfmABS7Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 8:
            _sfmABS8Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 9:
            _sfmABS9Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 10:
            _sfmABS10Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 11:
            _sfmABS11Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 12:
            _sfmABS12Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 13:
            _sfmABS13Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 14:
            _sfmABS14Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 15:
            _sfmABS15Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 16:
            _sfmABS16Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 17:
            _sfmABS17Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 18:
            _sfmABS18Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 19:
            _sfmABS19Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 20:
            _sfmABS20Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 21:
            _sfmABS21Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 22:
            _sfmABS22Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 23:
            _sfmABS23Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 24:
            _sfmABS24Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 25:
            _sfmABS25Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 26:
            _sfmABS26Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 27:
            _sfmABS27Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 28:
            _sfmABS28Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 29:
            _sfmABS29Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 30:
            _sfmABS30Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 31:
            _sfmABS31Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 32:
            _sfmABS32Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 33:
            _sfmABS33Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 34:
            _sfmABS34Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 35:
            _sfmABS35Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 36:
            _sfmABS36Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 37:
            _sfmABS37Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 38:
            _sfmABS38Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 39:
            _sfmABS39Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 40:
            _sfmABS40Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 41:
            _sfmABS41Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 42:
            _sfmABS42Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 43:
            _sfmABS43Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 44:
            _sfmABS44Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 45:
            _sfmABS45Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 46:
            _sfmABS46Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 47:
            _sfmABS47Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 48:
            _sfmABS48Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 49:
            _sfmABS49Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 50:
            _sfmABS50Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 100:
            _sfmABS100Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        default:
            // Should never get here
            assert(false);  
        }
        
    } // end match
    
};
#endif


// Copyright (c) 2012, Ofir Pele
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met: 
//    * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//    * Neither the name of the The Hebrew University of Jerusalem nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
