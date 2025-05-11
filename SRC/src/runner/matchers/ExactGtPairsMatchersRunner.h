#ifndef EXACTGTPAIRSMATCHERSRUNNER_H_
#define EXACTGTPAIRSMATCHERSRUNNER_H_

#include <ExactFastMatcher.h>
#include <isSimilar/PairsGt_IsSimilar_uchar.h>

class ExactGtPairsMatchersRunner {

private:
    
    int _thresh;
    
    typedef PairsGt_IsSimilar_uchar<0> T_TGT0;
typedef ExactFastMatcher<T_TGT0> T_GT0;
T_GT0* _efmGt0Ptr;
typedef PairsGt_IsSimilar_uchar<1> T_TGT1;
typedef ExactFastMatcher<T_TGT1> T_GT1;
T_GT1* _efmGt1Ptr;
typedef PairsGt_IsSimilar_uchar<2> T_TGT2;
typedef ExactFastMatcher<T_TGT2> T_GT2;
T_GT2* _efmGt2Ptr;
typedef PairsGt_IsSimilar_uchar<3> T_TGT3;
typedef ExactFastMatcher<T_TGT3> T_GT3;
T_GT3* _efmGt3Ptr;
typedef PairsGt_IsSimilar_uchar<4> T_TGT4;
typedef ExactFastMatcher<T_TGT4> T_GT4;
T_GT4* _efmGt4Ptr;
typedef PairsGt_IsSimilar_uchar<5> T_TGT5;
typedef ExactFastMatcher<T_TGT5> T_GT5;
T_GT5* _efmGt5Ptr;
typedef PairsGt_IsSimilar_uchar<6> T_TGT6;
typedef ExactFastMatcher<T_TGT6> T_GT6;
T_GT6* _efmGt6Ptr;
typedef PairsGt_IsSimilar_uchar<7> T_TGT7;
typedef ExactFastMatcher<T_TGT7> T_GT7;
T_GT7* _efmGt7Ptr;
typedef PairsGt_IsSimilar_uchar<8> T_TGT8;
typedef ExactFastMatcher<T_TGT8> T_GT8;
T_GT8* _efmGt8Ptr;
typedef PairsGt_IsSimilar_uchar<9> T_TGT9;
typedef ExactFastMatcher<T_TGT9> T_GT9;
T_GT9* _efmGt9Ptr;
typedef PairsGt_IsSimilar_uchar<10> T_TGT10;
typedef ExactFastMatcher<T_TGT10> T_GT10;
T_GT10* _efmGt10Ptr;
typedef PairsGt_IsSimilar_uchar<11> T_TGT11;
typedef ExactFastMatcher<T_TGT11> T_GT11;
T_GT11* _efmGt11Ptr;
typedef PairsGt_IsSimilar_uchar<12> T_TGT12;
typedef ExactFastMatcher<T_TGT12> T_GT12;
T_GT12* _efmGt12Ptr;
typedef PairsGt_IsSimilar_uchar<13> T_TGT13;
typedef ExactFastMatcher<T_TGT13> T_GT13;
T_GT13* _efmGt13Ptr;
typedef PairsGt_IsSimilar_uchar<14> T_TGT14;
typedef ExactFastMatcher<T_TGT14> T_GT14;
T_GT14* _efmGt14Ptr;
typedef PairsGt_IsSimilar_uchar<15> T_TGT15;
typedef ExactFastMatcher<T_TGT15> T_GT15;
T_GT15* _efmGt15Ptr;
typedef PairsGt_IsSimilar_uchar<16> T_TGT16;
typedef ExactFastMatcher<T_TGT16> T_GT16;
T_GT16* _efmGt16Ptr;
typedef PairsGt_IsSimilar_uchar<17> T_TGT17;
typedef ExactFastMatcher<T_TGT17> T_GT17;
T_GT17* _efmGt17Ptr;
typedef PairsGt_IsSimilar_uchar<18> T_TGT18;
typedef ExactFastMatcher<T_TGT18> T_GT18;
T_GT18* _efmGt18Ptr;
typedef PairsGt_IsSimilar_uchar<19> T_TGT19;
typedef ExactFastMatcher<T_TGT19> T_GT19;
T_GT19* _efmGt19Ptr;
typedef PairsGt_IsSimilar_uchar<20> T_TGT20;
typedef ExactFastMatcher<T_TGT20> T_GT20;
T_GT20* _efmGt20Ptr;
typedef PairsGt_IsSimilar_uchar<21> T_TGT21;
typedef ExactFastMatcher<T_TGT21> T_GT21;
T_GT21* _efmGt21Ptr;
typedef PairsGt_IsSimilar_uchar<22> T_TGT22;
typedef ExactFastMatcher<T_TGT22> T_GT22;
T_GT22* _efmGt22Ptr;
typedef PairsGt_IsSimilar_uchar<23> T_TGT23;
typedef ExactFastMatcher<T_TGT23> T_GT23;
T_GT23* _efmGt23Ptr;
typedef PairsGt_IsSimilar_uchar<24> T_TGT24;
typedef ExactFastMatcher<T_TGT24> T_GT24;
T_GT24* _efmGt24Ptr;
typedef PairsGt_IsSimilar_uchar<25> T_TGT25;
typedef ExactFastMatcher<T_TGT25> T_GT25;
T_GT25* _efmGt25Ptr;
typedef PairsGt_IsSimilar_uchar<26> T_TGT26;
typedef ExactFastMatcher<T_TGT26> T_GT26;
T_GT26* _efmGt26Ptr;
typedef PairsGt_IsSimilar_uchar<27> T_TGT27;
typedef ExactFastMatcher<T_TGT27> T_GT27;
T_GT27* _efmGt27Ptr;
typedef PairsGt_IsSimilar_uchar<28> T_TGT28;
typedef ExactFastMatcher<T_TGT28> T_GT28;
T_GT28* _efmGt28Ptr;
typedef PairsGt_IsSimilar_uchar<29> T_TGT29;
typedef ExactFastMatcher<T_TGT29> T_GT29;
T_GT29* _efmGt29Ptr;
typedef PairsGt_IsSimilar_uchar<30> T_TGT30;
typedef ExactFastMatcher<T_TGT30> T_GT30;
T_GT30* _efmGt30Ptr;
typedef PairsGt_IsSimilar_uchar<31> T_TGT31;
typedef ExactFastMatcher<T_TGT31> T_GT31;
T_GT31* _efmGt31Ptr;
typedef PairsGt_IsSimilar_uchar<32> T_TGT32;
typedef ExactFastMatcher<T_TGT32> T_GT32;
T_GT32* _efmGt32Ptr;
typedef PairsGt_IsSimilar_uchar<33> T_TGT33;
typedef ExactFastMatcher<T_TGT33> T_GT33;
T_GT33* _efmGt33Ptr;
typedef PairsGt_IsSimilar_uchar<34> T_TGT34;
typedef ExactFastMatcher<T_TGT34> T_GT34;
T_GT34* _efmGt34Ptr;
typedef PairsGt_IsSimilar_uchar<35> T_TGT35;
typedef ExactFastMatcher<T_TGT35> T_GT35;
T_GT35* _efmGt35Ptr;
typedef PairsGt_IsSimilar_uchar<36> T_TGT36;
typedef ExactFastMatcher<T_TGT36> T_GT36;
T_GT36* _efmGt36Ptr;
typedef PairsGt_IsSimilar_uchar<37> T_TGT37;
typedef ExactFastMatcher<T_TGT37> T_GT37;
T_GT37* _efmGt37Ptr;
typedef PairsGt_IsSimilar_uchar<38> T_TGT38;
typedef ExactFastMatcher<T_TGT38> T_GT38;
T_GT38* _efmGt38Ptr;
typedef PairsGt_IsSimilar_uchar<39> T_TGT39;
typedef ExactFastMatcher<T_TGT39> T_GT39;
T_GT39* _efmGt39Ptr;
typedef PairsGt_IsSimilar_uchar<40> T_TGT40;
typedef ExactFastMatcher<T_TGT40> T_GT40;
T_GT40* _efmGt40Ptr;
typedef PairsGt_IsSimilar_uchar<41> T_TGT41;
typedef ExactFastMatcher<T_TGT41> T_GT41;
T_GT41* _efmGt41Ptr;
typedef PairsGt_IsSimilar_uchar<42> T_TGT42;
typedef ExactFastMatcher<T_TGT42> T_GT42;
T_GT42* _efmGt42Ptr;
typedef PairsGt_IsSimilar_uchar<43> T_TGT43;
typedef ExactFastMatcher<T_TGT43> T_GT43;
T_GT43* _efmGt43Ptr;
typedef PairsGt_IsSimilar_uchar<44> T_TGT44;
typedef ExactFastMatcher<T_TGT44> T_GT44;
T_GT44* _efmGt44Ptr;
typedef PairsGt_IsSimilar_uchar<45> T_TGT45;
typedef ExactFastMatcher<T_TGT45> T_GT45;
T_GT45* _efmGt45Ptr;
typedef PairsGt_IsSimilar_uchar<46> T_TGT46;
typedef ExactFastMatcher<T_TGT46> T_GT46;
T_GT46* _efmGt46Ptr;
typedef PairsGt_IsSimilar_uchar<47> T_TGT47;
typedef ExactFastMatcher<T_TGT47> T_GT47;
T_GT47* _efmGt47Ptr;
typedef PairsGt_IsSimilar_uchar<48> T_TGT48;
typedef ExactFastMatcher<T_TGT48> T_GT48;
T_GT48* _efmGt48Ptr;
typedef PairsGt_IsSimilar_uchar<49> T_TGT49;
typedef ExactFastMatcher<T_TGT49> T_GT49;
T_GT49* _efmGt49Ptr;
typedef PairsGt_IsSimilar_uchar<50> T_TGT50;
typedef ExactFastMatcher<T_TGT50> T_GT50;
T_GT50* _efmGt50Ptr;
typedef PairsGt_IsSimilar_uchar<100> T_TGT100;
typedef ExactFastMatcher<T_TGT100> T_GT100;
T_GT100* _efmGt100Ptr;
    
    
public:    
            
    ExactGtPairsMatchersRunner() 
        : 
        _efmGt0Ptr(NULL),
_efmGt1Ptr(NULL),
_efmGt2Ptr(NULL),
_efmGt3Ptr(NULL),
_efmGt4Ptr(NULL),
_efmGt5Ptr(NULL),
_efmGt6Ptr(NULL),
_efmGt7Ptr(NULL),
_efmGt8Ptr(NULL),
_efmGt9Ptr(NULL),
_efmGt10Ptr(NULL),
_efmGt11Ptr(NULL),
_efmGt12Ptr(NULL),
_efmGt13Ptr(NULL),
_efmGt14Ptr(NULL),
_efmGt15Ptr(NULL),
_efmGt16Ptr(NULL),
_efmGt17Ptr(NULL),
_efmGt18Ptr(NULL),
_efmGt19Ptr(NULL),
_efmGt20Ptr(NULL),
_efmGt21Ptr(NULL),
_efmGt22Ptr(NULL),
_efmGt23Ptr(NULL),
_efmGt24Ptr(NULL),
_efmGt25Ptr(NULL),
_efmGt26Ptr(NULL),
_efmGt27Ptr(NULL),
_efmGt28Ptr(NULL),
_efmGt29Ptr(NULL),
_efmGt30Ptr(NULL),
_efmGt31Ptr(NULL),
_efmGt32Ptr(NULL),
_efmGt33Ptr(NULL),
_efmGt34Ptr(NULL),
_efmGt35Ptr(NULL),
_efmGt36Ptr(NULL),
_efmGt37Ptr(NULL),
_efmGt38Ptr(NULL),
_efmGt39Ptr(NULL),
_efmGt40Ptr(NULL),
_efmGt41Ptr(NULL),
_efmGt42Ptr(NULL),
_efmGt43Ptr(NULL),
_efmGt44Ptr(NULL),
_efmGt45Ptr(NULL),
_efmGt46Ptr(NULL),
_efmGt47Ptr(NULL),
_efmGt48Ptr(NULL),
_efmGt49Ptr(NULL),
_efmGt50Ptr(NULL),
_efmGt100Ptr(NULL)
            {}
    
    ~ExactGtPairsMatchersRunner() {
        delete _efmGt0Ptr;
        delete _efmGt1Ptr;
        delete _efmGt2Ptr;
        delete _efmGt3Ptr;
        delete _efmGt4Ptr;
        delete _efmGt5Ptr;
        delete _efmGt6Ptr;
        delete _efmGt7Ptr;
        delete _efmGt8Ptr;
        delete _efmGt9Ptr;
        delete _efmGt10Ptr;
        delete _efmGt11Ptr;
        delete _efmGt12Ptr;
        delete _efmGt13Ptr;
        delete _efmGt14Ptr;
        delete _efmGt15Ptr;
        delete _efmGt16Ptr;
        delete _efmGt17Ptr;
        delete _efmGt18Ptr;
        delete _efmGt19Ptr;
        delete _efmGt20Ptr;
        delete _efmGt21Ptr;
        delete _efmGt22Ptr;
        delete _efmGt23Ptr;
        delete _efmGt24Ptr;
        delete _efmGt25Ptr;
        delete _efmGt26Ptr;
        delete _efmGt27Ptr;
        delete _efmGt28Ptr;
        delete _efmGt29Ptr;
        delete _efmGt30Ptr;
        delete _efmGt31Ptr;
        delete _efmGt32Ptr;
        delete _efmGt33Ptr;
        delete _efmGt34Ptr;
        delete _efmGt35Ptr;
        delete _efmGt36Ptr;
        delete _efmGt37Ptr;
        delete _efmGt38Ptr;
        delete _efmGt39Ptr;
        delete _efmGt40Ptr;
        delete _efmGt41Ptr;
        delete _efmGt42Ptr;
        delete _efmGt43Ptr;
        delete _efmGt44Ptr;
        delete _efmGt45Ptr;
        delete _efmGt46Ptr;
        delete _efmGt47Ptr;
        delete _efmGt48Ptr;
        delete _efmGt49Ptr;
        delete _efmGt50Ptr;
        delete _efmGt100Ptr;
    }  
    
    void init(int thresh,int imWidthStep, IplImage* pattern, std::vector< pair<Point,Point> > maskPairs)
    {
    	_thresh= thresh;
    	
        switch (thresh) {
        case 0:
            _efmGt0Ptr= new T_GT0(imWidthStep,pattern,maskPairs);  break;
        case 1:
            _efmGt1Ptr= new T_GT1(imWidthStep,pattern,maskPairs);  break;
        case 2:
            _efmGt2Ptr= new T_GT2(imWidthStep,pattern,maskPairs);  break;
        case 3:
            _efmGt3Ptr= new T_GT3(imWidthStep,pattern,maskPairs);  break;
        case 4:
            _efmGt4Ptr= new T_GT4(imWidthStep,pattern,maskPairs);  break;
        case 5:
            _efmGt5Ptr= new T_GT5(imWidthStep,pattern,maskPairs);  break;
        case 6:
            _efmGt6Ptr= new T_GT6(imWidthStep,pattern,maskPairs);  break;
        case 7:
            _efmGt7Ptr= new T_GT7(imWidthStep,pattern,maskPairs);  break;
        case 8:
            _efmGt8Ptr= new T_GT8(imWidthStep,pattern,maskPairs);  break;
        case 9:
            _efmGt9Ptr= new T_GT9(imWidthStep,pattern,maskPairs);  break;
        case 10:
            _efmGt10Ptr= new T_GT10(imWidthStep,pattern,maskPairs);  break;
        case 11:
            _efmGt11Ptr= new T_GT11(imWidthStep,pattern,maskPairs);  break;
        case 12:
            _efmGt12Ptr= new T_GT12(imWidthStep,pattern,maskPairs);  break;
        case 13:
            _efmGt13Ptr= new T_GT13(imWidthStep,pattern,maskPairs);  break;
        case 14:
            _efmGt14Ptr= new T_GT14(imWidthStep,pattern,maskPairs);  break;
        case 15:
            _efmGt15Ptr= new T_GT15(imWidthStep,pattern,maskPairs);  break;
        case 16:
            _efmGt16Ptr= new T_GT16(imWidthStep,pattern,maskPairs);  break;
        case 17:
            _efmGt17Ptr= new T_GT17(imWidthStep,pattern,maskPairs);  break;
        case 18:
            _efmGt18Ptr= new T_GT18(imWidthStep,pattern,maskPairs);  break;
        case 19:
            _efmGt19Ptr= new T_GT19(imWidthStep,pattern,maskPairs);  break;
        case 20:
            _efmGt20Ptr= new T_GT20(imWidthStep,pattern,maskPairs);  break;
        case 21:
            _efmGt21Ptr= new T_GT21(imWidthStep,pattern,maskPairs);  break;
        case 22:
            _efmGt22Ptr= new T_GT22(imWidthStep,pattern,maskPairs);  break;
        case 23:
            _efmGt23Ptr= new T_GT23(imWidthStep,pattern,maskPairs);  break;
        case 24:
            _efmGt24Ptr= new T_GT24(imWidthStep,pattern,maskPairs);  break;
        case 25:
            _efmGt25Ptr= new T_GT25(imWidthStep,pattern,maskPairs);  break;
        case 26:
            _efmGt26Ptr= new T_GT26(imWidthStep,pattern,maskPairs);  break;
        case 27:
            _efmGt27Ptr= new T_GT27(imWidthStep,pattern,maskPairs);  break;
        case 28:
            _efmGt28Ptr= new T_GT28(imWidthStep,pattern,maskPairs);  break;
        case 29:
            _efmGt29Ptr= new T_GT29(imWidthStep,pattern,maskPairs);  break;
        case 30:
            _efmGt30Ptr= new T_GT30(imWidthStep,pattern,maskPairs);  break;
        case 31:
            _efmGt31Ptr= new T_GT31(imWidthStep,pattern,maskPairs);  break;
        case 32:
            _efmGt32Ptr= new T_GT32(imWidthStep,pattern,maskPairs);  break;
        case 33:
            _efmGt33Ptr= new T_GT33(imWidthStep,pattern,maskPairs);  break;
        case 34:
            _efmGt34Ptr= new T_GT34(imWidthStep,pattern,maskPairs);  break;
        case 35:
            _efmGt35Ptr= new T_GT35(imWidthStep,pattern,maskPairs);  break;
        case 36:
            _efmGt36Ptr= new T_GT36(imWidthStep,pattern,maskPairs);  break;
        case 37:
            _efmGt37Ptr= new T_GT37(imWidthStep,pattern,maskPairs);  break;
        case 38:
            _efmGt38Ptr= new T_GT38(imWidthStep,pattern,maskPairs);  break;
        case 39:
            _efmGt39Ptr= new T_GT39(imWidthStep,pattern,maskPairs);  break;
        case 40:
            _efmGt40Ptr= new T_GT40(imWidthStep,pattern,maskPairs);  break;
        case 41:
            _efmGt41Ptr= new T_GT41(imWidthStep,pattern,maskPairs);  break;
        case 42:
            _efmGt42Ptr= new T_GT42(imWidthStep,pattern,maskPairs);  break;
        case 43:
            _efmGt43Ptr= new T_GT43(imWidthStep,pattern,maskPairs);  break;
        case 44:
            _efmGt44Ptr= new T_GT44(imWidthStep,pattern,maskPairs);  break;
        case 45:
            _efmGt45Ptr= new T_GT45(imWidthStep,pattern,maskPairs);  break;
        case 46:
            _efmGt46Ptr= new T_GT46(imWidthStep,pattern,maskPairs);  break;
        case 47:
            _efmGt47Ptr= new T_GT47(imWidthStep,pattern,maskPairs);  break;
        case 48:
            _efmGt48Ptr= new T_GT48(imWidthStep,pattern,maskPairs);  break;
        case 49:
            _efmGt49Ptr= new T_GT49(imWidthStep,pattern,maskPairs);  break;
        case 50:
            _efmGt50Ptr= new T_GT50(imWidthStep,pattern,maskPairs);  break;
        case 100:
            _efmGt100Ptr= new T_GT100(imWidthStep,pattern,maskPairs);  break;
        default:
            // Should never get here
            assert(false);
            
        } // end switch
        
    } // end init
    
    
    void match(IplImage* image, CvMat* result) {
        switch (_thresh) {
        case 0:
            _efmGt0Ptr->cvHammingMatchTemplate(image,result);  break;
        case 1:
            _efmGt1Ptr->cvHammingMatchTemplate(image,result);  break;
        case 2:
            _efmGt2Ptr->cvHammingMatchTemplate(image,result);  break;
        case 3:
            _efmGt3Ptr->cvHammingMatchTemplate(image,result);  break;
        case 4:
            _efmGt4Ptr->cvHammingMatchTemplate(image,result);  break;
        case 5:
            _efmGt5Ptr->cvHammingMatchTemplate(image,result);  break;
        case 6:
            _efmGt6Ptr->cvHammingMatchTemplate(image,result);  break;
        case 7:
            _efmGt7Ptr->cvHammingMatchTemplate(image,result);  break;
        case 8:
            _efmGt8Ptr->cvHammingMatchTemplate(image,result);  break;
        case 9:
            _efmGt9Ptr->cvHammingMatchTemplate(image,result);  break;
        case 10:
            _efmGt10Ptr->cvHammingMatchTemplate(image,result);  break;
        case 11:
            _efmGt11Ptr->cvHammingMatchTemplate(image,result);  break;
        case 12:
            _efmGt12Ptr->cvHammingMatchTemplate(image,result);  break;
        case 13:
            _efmGt13Ptr->cvHammingMatchTemplate(image,result);  break;
        case 14:
            _efmGt14Ptr->cvHammingMatchTemplate(image,result);  break;
        case 15:
            _efmGt15Ptr->cvHammingMatchTemplate(image,result);  break;
        case 16:
            _efmGt16Ptr->cvHammingMatchTemplate(image,result);  break;
        case 17:
            _efmGt17Ptr->cvHammingMatchTemplate(image,result);  break;
        case 18:
            _efmGt18Ptr->cvHammingMatchTemplate(image,result);  break;
        case 19:
            _efmGt19Ptr->cvHammingMatchTemplate(image,result);  break;
        case 20:
            _efmGt20Ptr->cvHammingMatchTemplate(image,result);  break;
        case 21:
            _efmGt21Ptr->cvHammingMatchTemplate(image,result);  break;
        case 22:
            _efmGt22Ptr->cvHammingMatchTemplate(image,result);  break;
        case 23:
            _efmGt23Ptr->cvHammingMatchTemplate(image,result);  break;
        case 24:
            _efmGt24Ptr->cvHammingMatchTemplate(image,result);  break;
        case 25:
            _efmGt25Ptr->cvHammingMatchTemplate(image,result);  break;
        case 26:
            _efmGt26Ptr->cvHammingMatchTemplate(image,result);  break;
        case 27:
            _efmGt27Ptr->cvHammingMatchTemplate(image,result);  break;
        case 28:
            _efmGt28Ptr->cvHammingMatchTemplate(image,result);  break;
        case 29:
            _efmGt29Ptr->cvHammingMatchTemplate(image,result);  break;
        case 30:
            _efmGt30Ptr->cvHammingMatchTemplate(image,result);  break;
        case 31:
            _efmGt31Ptr->cvHammingMatchTemplate(image,result);  break;
        case 32:
            _efmGt32Ptr->cvHammingMatchTemplate(image,result);  break;
        case 33:
            _efmGt33Ptr->cvHammingMatchTemplate(image,result);  break;
        case 34:
            _efmGt34Ptr->cvHammingMatchTemplate(image,result);  break;
        case 35:
            _efmGt35Ptr->cvHammingMatchTemplate(image,result);  break;
        case 36:
            _efmGt36Ptr->cvHammingMatchTemplate(image,result);  break;
        case 37:
            _efmGt37Ptr->cvHammingMatchTemplate(image,result);  break;
        case 38:
            _efmGt38Ptr->cvHammingMatchTemplate(image,result);  break;
        case 39:
            _efmGt39Ptr->cvHammingMatchTemplate(image,result);  break;
        case 40:
            _efmGt40Ptr->cvHammingMatchTemplate(image,result);  break;
        case 41:
            _efmGt41Ptr->cvHammingMatchTemplate(image,result);  break;
        case 42:
            _efmGt42Ptr->cvHammingMatchTemplate(image,result);  break;
        case 43:
            _efmGt43Ptr->cvHammingMatchTemplate(image,result);  break;
        case 44:
            _efmGt44Ptr->cvHammingMatchTemplate(image,result);  break;
        case 45:
            _efmGt45Ptr->cvHammingMatchTemplate(image,result);  break;
        case 46:
            _efmGt46Ptr->cvHammingMatchTemplate(image,result);  break;
        case 47:
            _efmGt47Ptr->cvHammingMatchTemplate(image,result);  break;
        case 48:
            _efmGt48Ptr->cvHammingMatchTemplate(image,result);  break;
        case 49:
            _efmGt49Ptr->cvHammingMatchTemplate(image,result);  break;
        case 50:
            _efmGt50Ptr->cvHammingMatchTemplate(image,result);  break;
            
        case 100:
            _efmGt100Ptr->cvHammingMatchTemplate(image,result);  break;
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
