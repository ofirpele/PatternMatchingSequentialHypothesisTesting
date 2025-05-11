#ifndef LU_SEQGTPAIRSMATCHERSRUNNER_STAT_H_
#define LU_SEQGTPAIRSMATCHERSRUNNER_STAT_H_


#include <isSimilar/PairsGt_IsSimilar_uchar.h>

class LUSeqGtPairsMatchersRunnerStat {

private:
    
    int _thresh;
    
    typedef PairsGt_IsSimilar_uchar<0> T_TGT0;
typedef LUSeqFastMatcher<T_TGT0,true> T_GT0;
T_GT0* _sfmGt0Ptr;
typedef PairsGt_IsSimilar_uchar<1> T_TGT1;
typedef LUSeqFastMatcher<T_TGT1,true> T_GT1;
T_GT1* _sfmGt1Ptr;
typedef PairsGt_IsSimilar_uchar<2> T_TGT2;
typedef LUSeqFastMatcher<T_TGT2,true> T_GT2;
T_GT2* _sfmGt2Ptr;
typedef PairsGt_IsSimilar_uchar<3> T_TGT3;
typedef LUSeqFastMatcher<T_TGT3,true> T_GT3;
T_GT3* _sfmGt3Ptr;
typedef PairsGt_IsSimilar_uchar<4> T_TGT4;
typedef LUSeqFastMatcher<T_TGT4,true> T_GT4;
T_GT4* _sfmGt4Ptr;
typedef PairsGt_IsSimilar_uchar<5> T_TGT5;
typedef LUSeqFastMatcher<T_TGT5,true> T_GT5;
T_GT5* _sfmGt5Ptr;
typedef PairsGt_IsSimilar_uchar<6> T_TGT6;
typedef LUSeqFastMatcher<T_TGT6,true> T_GT6;
T_GT6* _sfmGt6Ptr;
typedef PairsGt_IsSimilar_uchar<7> T_TGT7;
typedef LUSeqFastMatcher<T_TGT7,true> T_GT7;
T_GT7* _sfmGt7Ptr;
typedef PairsGt_IsSimilar_uchar<8> T_TGT8;
typedef LUSeqFastMatcher<T_TGT8,true> T_GT8;
T_GT8* _sfmGt8Ptr;
typedef PairsGt_IsSimilar_uchar<9> T_TGT9;
typedef LUSeqFastMatcher<T_TGT9,true> T_GT9;
T_GT9* _sfmGt9Ptr;
typedef PairsGt_IsSimilar_uchar<10> T_TGT10;
typedef LUSeqFastMatcher<T_TGT10,true> T_GT10;
T_GT10* _sfmGt10Ptr;
typedef PairsGt_IsSimilar_uchar<11> T_TGT11;
typedef LUSeqFastMatcher<T_TGT11,true> T_GT11;
T_GT11* _sfmGt11Ptr;
typedef PairsGt_IsSimilar_uchar<12> T_TGT12;
typedef LUSeqFastMatcher<T_TGT12,true> T_GT12;
T_GT12* _sfmGt12Ptr;
typedef PairsGt_IsSimilar_uchar<13> T_TGT13;
typedef LUSeqFastMatcher<T_TGT13,true> T_GT13;
T_GT13* _sfmGt13Ptr;
typedef PairsGt_IsSimilar_uchar<14> T_TGT14;
typedef LUSeqFastMatcher<T_TGT14,true> T_GT14;
T_GT14* _sfmGt14Ptr;
typedef PairsGt_IsSimilar_uchar<15> T_TGT15;
typedef LUSeqFastMatcher<T_TGT15,true> T_GT15;
T_GT15* _sfmGt15Ptr;
typedef PairsGt_IsSimilar_uchar<16> T_TGT16;
typedef LUSeqFastMatcher<T_TGT16,true> T_GT16;
T_GT16* _sfmGt16Ptr;
typedef PairsGt_IsSimilar_uchar<17> T_TGT17;
typedef LUSeqFastMatcher<T_TGT17,true> T_GT17;
T_GT17* _sfmGt17Ptr;
typedef PairsGt_IsSimilar_uchar<18> T_TGT18;
typedef LUSeqFastMatcher<T_TGT18,true> T_GT18;
T_GT18* _sfmGt18Ptr;
typedef PairsGt_IsSimilar_uchar<19> T_TGT19;
typedef LUSeqFastMatcher<T_TGT19,true> T_GT19;
T_GT19* _sfmGt19Ptr;
typedef PairsGt_IsSimilar_uchar<20> T_TGT20;
typedef LUSeqFastMatcher<T_TGT20,true> T_GT20;
T_GT20* _sfmGt20Ptr;
typedef PairsGt_IsSimilar_uchar<21> T_TGT21;
typedef LUSeqFastMatcher<T_TGT21,true> T_GT21;
T_GT21* _sfmGt21Ptr;
typedef PairsGt_IsSimilar_uchar<22> T_TGT22;
typedef LUSeqFastMatcher<T_TGT22,true> T_GT22;
T_GT22* _sfmGt22Ptr;
typedef PairsGt_IsSimilar_uchar<23> T_TGT23;
typedef LUSeqFastMatcher<T_TGT23,true> T_GT23;
T_GT23* _sfmGt23Ptr;
typedef PairsGt_IsSimilar_uchar<24> T_TGT24;
typedef LUSeqFastMatcher<T_TGT24,true> T_GT24;
T_GT24* _sfmGt24Ptr;
typedef PairsGt_IsSimilar_uchar<25> T_TGT25;
typedef LUSeqFastMatcher<T_TGT25,true> T_GT25;
T_GT25* _sfmGt25Ptr;
typedef PairsGt_IsSimilar_uchar<26> T_TGT26;
typedef LUSeqFastMatcher<T_TGT26,true> T_GT26;
T_GT26* _sfmGt26Ptr;
typedef PairsGt_IsSimilar_uchar<27> T_TGT27;
typedef LUSeqFastMatcher<T_TGT27,true> T_GT27;
T_GT27* _sfmGt27Ptr;
typedef PairsGt_IsSimilar_uchar<28> T_TGT28;
typedef LUSeqFastMatcher<T_TGT28,true> T_GT28;
T_GT28* _sfmGt28Ptr;
typedef PairsGt_IsSimilar_uchar<29> T_TGT29;
typedef LUSeqFastMatcher<T_TGT29,true> T_GT29;
T_GT29* _sfmGt29Ptr;
typedef PairsGt_IsSimilar_uchar<30> T_TGT30;
typedef LUSeqFastMatcher<T_TGT30,true> T_GT30;
T_GT30* _sfmGt30Ptr;
typedef PairsGt_IsSimilar_uchar<31> T_TGT31;
typedef LUSeqFastMatcher<T_TGT31,true> T_GT31;
T_GT31* _sfmGt31Ptr;
typedef PairsGt_IsSimilar_uchar<32> T_TGT32;
typedef LUSeqFastMatcher<T_TGT32,true> T_GT32;
T_GT32* _sfmGt32Ptr;
typedef PairsGt_IsSimilar_uchar<33> T_TGT33;
typedef LUSeqFastMatcher<T_TGT33,true> T_GT33;
T_GT33* _sfmGt33Ptr;
typedef PairsGt_IsSimilar_uchar<34> T_TGT34;
typedef LUSeqFastMatcher<T_TGT34,true> T_GT34;
T_GT34* _sfmGt34Ptr;
typedef PairsGt_IsSimilar_uchar<35> T_TGT35;
typedef LUSeqFastMatcher<T_TGT35,true> T_GT35;
T_GT35* _sfmGt35Ptr;
typedef PairsGt_IsSimilar_uchar<36> T_TGT36;
typedef LUSeqFastMatcher<T_TGT36,true> T_GT36;
T_GT36* _sfmGt36Ptr;
typedef PairsGt_IsSimilar_uchar<37> T_TGT37;
typedef LUSeqFastMatcher<T_TGT37,true> T_GT37;
T_GT37* _sfmGt37Ptr;
typedef PairsGt_IsSimilar_uchar<38> T_TGT38;
typedef LUSeqFastMatcher<T_TGT38,true> T_GT38;
T_GT38* _sfmGt38Ptr;
typedef PairsGt_IsSimilar_uchar<39> T_TGT39;
typedef LUSeqFastMatcher<T_TGT39,true> T_GT39;
T_GT39* _sfmGt39Ptr;
typedef PairsGt_IsSimilar_uchar<40> T_TGT40;
typedef LUSeqFastMatcher<T_TGT40,true> T_GT40;
T_GT40* _sfmGt40Ptr;
typedef PairsGt_IsSimilar_uchar<41> T_TGT41;
typedef LUSeqFastMatcher<T_TGT41,true> T_GT41;
T_GT41* _sfmGt41Ptr;
typedef PairsGt_IsSimilar_uchar<42> T_TGT42;
typedef LUSeqFastMatcher<T_TGT42,true> T_GT42;
T_GT42* _sfmGt42Ptr;
typedef PairsGt_IsSimilar_uchar<43> T_TGT43;
typedef LUSeqFastMatcher<T_TGT43,true> T_GT43;
T_GT43* _sfmGt43Ptr;
typedef PairsGt_IsSimilar_uchar<44> T_TGT44;
typedef LUSeqFastMatcher<T_TGT44,true> T_GT44;
T_GT44* _sfmGt44Ptr;
typedef PairsGt_IsSimilar_uchar<45> T_TGT45;
typedef LUSeqFastMatcher<T_TGT45,true> T_GT45;
T_GT45* _sfmGt45Ptr;
typedef PairsGt_IsSimilar_uchar<46> T_TGT46;
typedef LUSeqFastMatcher<T_TGT46,true> T_GT46;
T_GT46* _sfmGt46Ptr;
typedef PairsGt_IsSimilar_uchar<47> T_TGT47;
typedef LUSeqFastMatcher<T_TGT47,true> T_GT47;
T_GT47* _sfmGt47Ptr;
typedef PairsGt_IsSimilar_uchar<48> T_TGT48;
typedef LUSeqFastMatcher<T_TGT48,true> T_GT48;
T_GT48* _sfmGt48Ptr;
typedef PairsGt_IsSimilar_uchar<49> T_TGT49;
typedef LUSeqFastMatcher<T_TGT49,true> T_GT49;
T_GT49* _sfmGt49Ptr;
typedef PairsGt_IsSimilar_uchar<50> T_TGT50;
typedef LUSeqFastMatcher<T_TGT50,true> T_GT50;
T_GT50* _sfmGt50Ptr;
typedef PairsGt_IsSimilar_uchar<100> T_TGT100;
typedef LUSeqFastMatcher<T_TGT100,true> T_GT100;
T_GT100* _sfmGt100Ptr;
    
    
public:    
            
    LUSeqGtPairsMatchersRunnerStat() 
        : 
        _sfmGt0Ptr(NULL),
_sfmGt1Ptr(NULL),
_sfmGt2Ptr(NULL),
_sfmGt3Ptr(NULL),
_sfmGt4Ptr(NULL),
_sfmGt5Ptr(NULL),
_sfmGt6Ptr(NULL),
_sfmGt7Ptr(NULL),
_sfmGt8Ptr(NULL),
_sfmGt9Ptr(NULL),
_sfmGt10Ptr(NULL),
_sfmGt11Ptr(NULL),
_sfmGt12Ptr(NULL),
_sfmGt13Ptr(NULL),
_sfmGt14Ptr(NULL),
_sfmGt15Ptr(NULL),
_sfmGt16Ptr(NULL),
_sfmGt17Ptr(NULL),
_sfmGt18Ptr(NULL),
_sfmGt19Ptr(NULL),
_sfmGt20Ptr(NULL),
_sfmGt21Ptr(NULL),
_sfmGt22Ptr(NULL),
_sfmGt23Ptr(NULL),
_sfmGt24Ptr(NULL),
_sfmGt25Ptr(NULL),
_sfmGt26Ptr(NULL),
_sfmGt27Ptr(NULL),
_sfmGt28Ptr(NULL),
_sfmGt29Ptr(NULL),
_sfmGt30Ptr(NULL),
_sfmGt31Ptr(NULL),
_sfmGt32Ptr(NULL),
_sfmGt33Ptr(NULL),
_sfmGt34Ptr(NULL),
_sfmGt35Ptr(NULL),
_sfmGt36Ptr(NULL),
_sfmGt37Ptr(NULL),
_sfmGt38Ptr(NULL),
_sfmGt39Ptr(NULL),
_sfmGt40Ptr(NULL),
_sfmGt41Ptr(NULL),
_sfmGt42Ptr(NULL),
_sfmGt43Ptr(NULL),
_sfmGt44Ptr(NULL),
_sfmGt45Ptr(NULL),
_sfmGt46Ptr(NULL),
_sfmGt47Ptr(NULL),
_sfmGt48Ptr(NULL),
_sfmGt49Ptr(NULL),
_sfmGt50Ptr(NULL),
_sfmGt100Ptr(NULL)
            {}
    
    ~LUSeqGtPairsMatchersRunnerStat() {
        delete _sfmGt0Ptr;
        delete _sfmGt1Ptr;
        delete _sfmGt2Ptr;
        delete _sfmGt3Ptr;
        delete _sfmGt4Ptr;
        delete _sfmGt5Ptr;
        delete _sfmGt6Ptr;
        delete _sfmGt7Ptr;
        delete _sfmGt8Ptr;
        delete _sfmGt9Ptr;
        delete _sfmGt10Ptr;
        delete _sfmGt11Ptr;
        delete _sfmGt12Ptr;
        delete _sfmGt13Ptr;
        delete _sfmGt14Ptr;
        delete _sfmGt15Ptr;
        delete _sfmGt16Ptr;
        delete _sfmGt17Ptr;
        delete _sfmGt18Ptr;
        delete _sfmGt19Ptr;
        delete _sfmGt20Ptr;
        delete _sfmGt21Ptr;
        delete _sfmGt22Ptr;
        delete _sfmGt23Ptr;
        delete _sfmGt24Ptr;
        delete _sfmGt25Ptr;
        delete _sfmGt26Ptr;
        delete _sfmGt27Ptr;
        delete _sfmGt28Ptr;
        delete _sfmGt29Ptr;
        delete _sfmGt30Ptr;
        delete _sfmGt31Ptr;
        delete _sfmGt32Ptr;
        delete _sfmGt33Ptr;
        delete _sfmGt34Ptr;
        delete _sfmGt35Ptr;
        delete _sfmGt36Ptr;
        delete _sfmGt37Ptr;
        delete _sfmGt38Ptr;
        delete _sfmGt39Ptr;
        delete _sfmGt40Ptr;
        delete _sfmGt41Ptr;
        delete _sfmGt42Ptr;
        delete _sfmGt43Ptr;
        delete _sfmGt44Ptr;
        delete _sfmGt45Ptr;
        delete _sfmGt46Ptr;
        delete _sfmGt47Ptr;
        delete _sfmGt48Ptr;
        delete _sfmGt49Ptr;
        delete _sfmGt50Ptr;
        delete _sfmGt100Ptr;
    }  
    
    void init(int thresh,
              
              int imWidthStep, int imWidth, int imHeight, 
              IplImage* pattern, 
              std::vector< std::pair<Point,Point> > maskPairs,
              const double& falseNegative, 
              const double& maxOcclusion,
              
              std::vector< std::pair<Point,Point> >& LUmaskPairs,
              const double& LUfalseNegative,
              const double& LUmaxOcclusion,
              const int& LUX,
              const int& LUY)
        {
        _thresh= thresh;
                
        switch (thresh) {
        case 0:
            _sfmGt0Ptr= new T_GT0(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 1:
            _sfmGt1Ptr= new T_GT1(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 2:
            _sfmGt2Ptr= new T_GT2(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 3:
            _sfmGt3Ptr= new T_GT3(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 4:
            _sfmGt4Ptr= new T_GT4(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 5:
            _sfmGt5Ptr= new T_GT5(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 6:
            _sfmGt6Ptr= new T_GT6(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 7:
            _sfmGt7Ptr= new T_GT7(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 8:
            _sfmGt8Ptr= new T_GT8(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 9:
            _sfmGt9Ptr= new T_GT9(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 10:
            _sfmGt10Ptr= new T_GT10(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 11:
            _sfmGt11Ptr= new T_GT11(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 12:
            _sfmGt12Ptr= new T_GT12(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 13:
            _sfmGt13Ptr= new T_GT13(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 14:
            _sfmGt14Ptr= new T_GT14(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 15:
            _sfmGt15Ptr= new T_GT15(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 16:
            _sfmGt16Ptr= new T_GT16(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 17:
            _sfmGt17Ptr= new T_GT17(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 18:
            _sfmGt18Ptr= new T_GT18(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 19:
            _sfmGt19Ptr= new T_GT19(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 20:
            _sfmGt20Ptr= new T_GT20(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 21:
            _sfmGt21Ptr= new T_GT21(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 22:
            _sfmGt22Ptr= new T_GT22(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 23:
            _sfmGt23Ptr= new T_GT23(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 24:
            _sfmGt24Ptr= new T_GT24(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 25:
            _sfmGt25Ptr= new T_GT25(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 26:
            _sfmGt26Ptr= new T_GT26(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 27:
            _sfmGt27Ptr= new T_GT27(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 28:
            _sfmGt28Ptr= new T_GT28(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 29:
            _sfmGt29Ptr= new T_GT29(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 30:
            _sfmGt30Ptr= new T_GT30(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 31:
            _sfmGt31Ptr= new T_GT31(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 32:
            _sfmGt32Ptr= new T_GT32(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 33:
            _sfmGt33Ptr= new T_GT33(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 34:
            _sfmGt34Ptr= new T_GT34(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 35:
            _sfmGt35Ptr= new T_GT35(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 36:
            _sfmGt36Ptr= new T_GT36(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 37:
            _sfmGt37Ptr= new T_GT37(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 38:
            _sfmGt38Ptr= new T_GT38(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 39:
            _sfmGt39Ptr= new T_GT39(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 40:
            _sfmGt40Ptr= new T_GT40(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 41:
            _sfmGt41Ptr= new T_GT41(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 42:
            _sfmGt42Ptr= new T_GT42(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 43:
            _sfmGt43Ptr= new T_GT43(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 44:
            _sfmGt44Ptr= new T_GT44(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 45:
            _sfmGt45Ptr= new T_GT45(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 46:
            _sfmGt46Ptr= new T_GT46(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 47:
            _sfmGt47Ptr= new T_GT47(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 48:
            _sfmGt48Ptr= new T_GT48(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 49:
            _sfmGt49Ptr= new T_GT49(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 50:
            _sfmGt50Ptr= new T_GT50(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
        case 100:
            _sfmGt100Ptr= new T_GT100(imWidthStep, imWidth, imHeight,pattern,maskPairs, falseNegative, maxOcclusion,LUmaskPairs,LUfalseNegative,LUmaxOcclusion,LUX,LUY);  break;
            
        default:
            // Should never get here
            assert(false);
            
        } // end switch
        
    } // end init
    
    
    void match(IplImage* image, CvMat* result) {
        switch (_thresh) {
        case 0:
            _sfmGt0Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 1:
            _sfmGt1Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 2:
            _sfmGt2Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 3:
            _sfmGt3Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 4:
            _sfmGt4Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 5:
            _sfmGt5Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 6:
            _sfmGt6Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 7:
            _sfmGt7Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 8:
            _sfmGt8Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 9:
            _sfmGt9Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 10:
            _sfmGt10Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 11:
            _sfmGt11Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 12:
            _sfmGt12Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 13:
            _sfmGt13Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 14:
            _sfmGt14Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 15:
            _sfmGt15Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 16:
            _sfmGt16Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 17:
            _sfmGt17Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 18:
            _sfmGt18Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 19:
            _sfmGt19Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 20:
            _sfmGt20Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 21:
            _sfmGt21Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 22:
            _sfmGt22Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 23:
            _sfmGt23Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 24:
            _sfmGt24Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 25:
            _sfmGt25Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 26:
            _sfmGt26Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 27:
            _sfmGt27Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 28:
            _sfmGt28Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 29:
            _sfmGt29Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 30:
            _sfmGt30Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 31:
            _sfmGt31Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 32:
            _sfmGt32Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 33:
            _sfmGt33Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 34:
            _sfmGt34Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 35:
            _sfmGt35Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 36:
            _sfmGt36Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 37:
            _sfmGt37Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 38:
            _sfmGt38Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 39:
            _sfmGt39Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 40:
            _sfmGt40Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 41:
            _sfmGt41Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 42:
            _sfmGt42Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 43:
            _sfmGt43Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 44:
            _sfmGt44Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 45:
            _sfmGt45Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 46:
            _sfmGt46Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 47:
            _sfmGt47Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 48:
            _sfmGt48Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 49:
            _sfmGt49Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 50:
            _sfmGt50Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 100:
            _sfmGt100Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
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
