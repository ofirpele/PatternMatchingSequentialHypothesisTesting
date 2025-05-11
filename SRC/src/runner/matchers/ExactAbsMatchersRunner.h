#ifndef EXACTABSMATCHERSRUNNER_H_
#define EXACTABSMATCHERSRUNNER_H_

#include <ExactFastMatcher.h>
#include <isSimilar/DiffAbs_IsSimilar_uchar.h>

class ExactAbsMatchersRunner {

private:
    
    int _thresh;
    
    typedef DiffAbs_IsSimilar_uchar<0> T_TABS0;
    typedef ExactFastMatcher<T_TABS0> T_ABS0;
    T_ABS0* _efmAbs0Ptr;
    typedef DiffAbs_IsSimilar_uchar<1> T_TABS1;
    typedef ExactFastMatcher<T_TABS1> T_ABS1;
    T_ABS1* _efmAbs1Ptr;
    typedef DiffAbs_IsSimilar_uchar<2> T_TABS2;
    typedef ExactFastMatcher<T_TABS2> T_ABS2;
    T_ABS2* _efmAbs2Ptr;
    typedef DiffAbs_IsSimilar_uchar<3> T_TABS3;
    typedef ExactFastMatcher<T_TABS3> T_ABS3;
    T_ABS3* _efmAbs3Ptr;
    typedef DiffAbs_IsSimilar_uchar<4> T_TABS4;
    typedef ExactFastMatcher<T_TABS4> T_ABS4;
    T_ABS4* _efmAbs4Ptr;
    typedef DiffAbs_IsSimilar_uchar<5> T_TABS5;
    typedef ExactFastMatcher<T_TABS5> T_ABS5;
    T_ABS5* _efmAbs5Ptr;
    typedef DiffAbs_IsSimilar_uchar<6> T_TABS6;
    typedef ExactFastMatcher<T_TABS6> T_ABS6;
    T_ABS6* _efmAbs6Ptr;
    typedef DiffAbs_IsSimilar_uchar<7> T_TABS7;
    typedef ExactFastMatcher<T_TABS7> T_ABS7;
    T_ABS7* _efmAbs7Ptr;
    typedef DiffAbs_IsSimilar_uchar<8> T_TABS8;
    typedef ExactFastMatcher<T_TABS8> T_ABS8;
    T_ABS8* _efmAbs8Ptr;
    typedef DiffAbs_IsSimilar_uchar<9> T_TABS9;
    typedef ExactFastMatcher<T_TABS9> T_ABS9;
    T_ABS9* _efmAbs9Ptr;
    typedef DiffAbs_IsSimilar_uchar<10> T_TABS10;
    typedef ExactFastMatcher<T_TABS10> T_ABS10;
    T_ABS10* _efmAbs10Ptr;
    typedef DiffAbs_IsSimilar_uchar<11> T_TABS11;
    typedef ExactFastMatcher<T_TABS11> T_ABS11;
    T_ABS11* _efmAbs11Ptr;
    typedef DiffAbs_IsSimilar_uchar<12> T_TABS12;
    typedef ExactFastMatcher<T_TABS12> T_ABS12;
    T_ABS12* _efmAbs12Ptr;
    typedef DiffAbs_IsSimilar_uchar<13> T_TABS13;
    typedef ExactFastMatcher<T_TABS13> T_ABS13;
    T_ABS13* _efmAbs13Ptr;
    typedef DiffAbs_IsSimilar_uchar<14> T_TABS14;
    typedef ExactFastMatcher<T_TABS14> T_ABS14;
    T_ABS14* _efmAbs14Ptr;
    typedef DiffAbs_IsSimilar_uchar<15> T_TABS15;
    typedef ExactFastMatcher<T_TABS15> T_ABS15;
    T_ABS15* _efmAbs15Ptr;
    typedef DiffAbs_IsSimilar_uchar<16> T_TABS16;
    typedef ExactFastMatcher<T_TABS16> T_ABS16;
    T_ABS16* _efmAbs16Ptr;
    typedef DiffAbs_IsSimilar_uchar<17> T_TABS17;
    typedef ExactFastMatcher<T_TABS17> T_ABS17;
    T_ABS17* _efmAbs17Ptr;
    typedef DiffAbs_IsSimilar_uchar<18> T_TABS18;
    typedef ExactFastMatcher<T_TABS18> T_ABS18;
    T_ABS18* _efmAbs18Ptr;
    typedef DiffAbs_IsSimilar_uchar<19> T_TABS19;
    typedef ExactFastMatcher<T_TABS19> T_ABS19;
    T_ABS19* _efmAbs19Ptr;
    typedef DiffAbs_IsSimilar_uchar<20> T_TABS20;
    typedef ExactFastMatcher<T_TABS20> T_ABS20;
    T_ABS20* _efmAbs20Ptr;
    typedef DiffAbs_IsSimilar_uchar<21> T_TABS21;
    typedef ExactFastMatcher<T_TABS21> T_ABS21;
    T_ABS21* _efmAbs21Ptr;
    typedef DiffAbs_IsSimilar_uchar<22> T_TABS22;
    typedef ExactFastMatcher<T_TABS22> T_ABS22;
    T_ABS22* _efmAbs22Ptr;
    typedef DiffAbs_IsSimilar_uchar<23> T_TABS23;
    typedef ExactFastMatcher<T_TABS23> T_ABS23;
    T_ABS23* _efmAbs23Ptr;
    typedef DiffAbs_IsSimilar_uchar<24> T_TABS24;
    typedef ExactFastMatcher<T_TABS24> T_ABS24;
    T_ABS24* _efmAbs24Ptr;
    typedef DiffAbs_IsSimilar_uchar<25> T_TABS25;
    typedef ExactFastMatcher<T_TABS25> T_ABS25;
    T_ABS25* _efmAbs25Ptr;
    typedef DiffAbs_IsSimilar_uchar<26> T_TABS26;
    typedef ExactFastMatcher<T_TABS26> T_ABS26;
    T_ABS26* _efmAbs26Ptr;
    typedef DiffAbs_IsSimilar_uchar<27> T_TABS27;
    typedef ExactFastMatcher<T_TABS27> T_ABS27;
    T_ABS27* _efmAbs27Ptr;
    typedef DiffAbs_IsSimilar_uchar<28> T_TABS28;
    typedef ExactFastMatcher<T_TABS28> T_ABS28;
    T_ABS28* _efmAbs28Ptr;
    typedef DiffAbs_IsSimilar_uchar<29> T_TABS29;
    typedef ExactFastMatcher<T_TABS29> T_ABS29;
    T_ABS29* _efmAbs29Ptr;
    typedef DiffAbs_IsSimilar_uchar<30> T_TABS30;
    typedef ExactFastMatcher<T_TABS30> T_ABS30;
    T_ABS30* _efmAbs30Ptr;
    typedef DiffAbs_IsSimilar_uchar<31> T_TABS31;
    typedef ExactFastMatcher<T_TABS31> T_ABS31;
    T_ABS31* _efmAbs31Ptr;
    typedef DiffAbs_IsSimilar_uchar<32> T_TABS32;
    typedef ExactFastMatcher<T_TABS32> T_ABS32;
    T_ABS32* _efmAbs32Ptr;
    typedef DiffAbs_IsSimilar_uchar<33> T_TABS33;
    typedef ExactFastMatcher<T_TABS33> T_ABS33;
    T_ABS33* _efmAbs33Ptr;
    typedef DiffAbs_IsSimilar_uchar<34> T_TABS34;
    typedef ExactFastMatcher<T_TABS34> T_ABS34;
    T_ABS34* _efmAbs34Ptr;
    typedef DiffAbs_IsSimilar_uchar<35> T_TABS35;
    typedef ExactFastMatcher<T_TABS35> T_ABS35;
    T_ABS35* _efmAbs35Ptr;
    typedef DiffAbs_IsSimilar_uchar<36> T_TABS36;
    typedef ExactFastMatcher<T_TABS36> T_ABS36;
    T_ABS36* _efmAbs36Ptr;
    typedef DiffAbs_IsSimilar_uchar<37> T_TABS37;
    typedef ExactFastMatcher<T_TABS37> T_ABS37;
    T_ABS37* _efmAbs37Ptr;
    typedef DiffAbs_IsSimilar_uchar<38> T_TABS38;
    typedef ExactFastMatcher<T_TABS38> T_ABS38;
    T_ABS38* _efmAbs38Ptr;
    typedef DiffAbs_IsSimilar_uchar<39> T_TABS39;
    typedef ExactFastMatcher<T_TABS39> T_ABS39;
    T_ABS39* _efmAbs39Ptr;
    typedef DiffAbs_IsSimilar_uchar<40> T_TABS40;
    typedef ExactFastMatcher<T_TABS40> T_ABS40;
    T_ABS40* _efmAbs40Ptr;
    typedef DiffAbs_IsSimilar_uchar<41> T_TABS41;
    typedef ExactFastMatcher<T_TABS41> T_ABS41;
    T_ABS41* _efmAbs41Ptr;
    typedef DiffAbs_IsSimilar_uchar<42> T_TABS42;
    typedef ExactFastMatcher<T_TABS42> T_ABS42;
    T_ABS42* _efmAbs42Ptr;
    typedef DiffAbs_IsSimilar_uchar<43> T_TABS43;
    typedef ExactFastMatcher<T_TABS43> T_ABS43;
    T_ABS43* _efmAbs43Ptr;
    typedef DiffAbs_IsSimilar_uchar<44> T_TABS44;
    typedef ExactFastMatcher<T_TABS44> T_ABS44;
    T_ABS44* _efmAbs44Ptr;
    typedef DiffAbs_IsSimilar_uchar<45> T_TABS45;
    typedef ExactFastMatcher<T_TABS45> T_ABS45;
    T_ABS45* _efmAbs45Ptr;
    typedef DiffAbs_IsSimilar_uchar<46> T_TABS46;
    typedef ExactFastMatcher<T_TABS46> T_ABS46;
    T_ABS46* _efmAbs46Ptr;
    typedef DiffAbs_IsSimilar_uchar<47> T_TABS47;
    typedef ExactFastMatcher<T_TABS47> T_ABS47;
    T_ABS47* _efmAbs47Ptr;
    typedef DiffAbs_IsSimilar_uchar<48> T_TABS48;
    typedef ExactFastMatcher<T_TABS48> T_ABS48;
    T_ABS48* _efmAbs48Ptr;
    typedef DiffAbs_IsSimilar_uchar<49> T_TABS49;
    typedef ExactFastMatcher<T_TABS49> T_ABS49;
    T_ABS49* _efmAbs49Ptr;
    typedef DiffAbs_IsSimilar_uchar<50> T_TABS50;
    typedef ExactFastMatcher<T_TABS50> T_ABS50;
    T_ABS50* _efmAbs50Ptr;
    typedef DiffAbs_IsSimilar_uchar<100> T_TABS100;
    typedef ExactFastMatcher<T_TABS100> T_ABS100;
    T_ABS100* _efmAbs100Ptr;
        
    
public:    
            
    ExactAbsMatchersRunner() 
        : 
        _efmAbs0Ptr(NULL),
            _efmAbs1Ptr(NULL),
            _efmAbs2Ptr(NULL),
            _efmAbs3Ptr(NULL),
            _efmAbs4Ptr(NULL),
            _efmAbs5Ptr(NULL),
            _efmAbs6Ptr(NULL),
            _efmAbs7Ptr(NULL),
            _efmAbs8Ptr(NULL),
            _efmAbs9Ptr(NULL),
            _efmAbs10Ptr(NULL),
            _efmAbs11Ptr(NULL),
            _efmAbs12Ptr(NULL),
            _efmAbs13Ptr(NULL),
            _efmAbs14Ptr(NULL),
            _efmAbs15Ptr(NULL),
            _efmAbs16Ptr(NULL),
            _efmAbs17Ptr(NULL),
            _efmAbs18Ptr(NULL),
            _efmAbs19Ptr(NULL),
            _efmAbs20Ptr(NULL),
            _efmAbs21Ptr(NULL),
            _efmAbs22Ptr(NULL),
            _efmAbs23Ptr(NULL),
            _efmAbs24Ptr(NULL),
            _efmAbs25Ptr(NULL),
            _efmAbs26Ptr(NULL),
            _efmAbs27Ptr(NULL),
            _efmAbs28Ptr(NULL),
            _efmAbs29Ptr(NULL),
            _efmAbs30Ptr(NULL),
            _efmAbs31Ptr(NULL),
            _efmAbs32Ptr(NULL),
            _efmAbs33Ptr(NULL),
            _efmAbs34Ptr(NULL),
            _efmAbs35Ptr(NULL),
            _efmAbs36Ptr(NULL),
            _efmAbs37Ptr(NULL),
            _efmAbs38Ptr(NULL),
            _efmAbs39Ptr(NULL),
            _efmAbs40Ptr(NULL),
            _efmAbs41Ptr(NULL),
            _efmAbs42Ptr(NULL),
            _efmAbs43Ptr(NULL),
            _efmAbs44Ptr(NULL),
            _efmAbs45Ptr(NULL),
            _efmAbs46Ptr(NULL),
            _efmAbs47Ptr(NULL),
            _efmAbs48Ptr(NULL),
            _efmAbs49Ptr(NULL),
            _efmAbs50Ptr(NULL),
            _efmAbs100Ptr(NULL)
            {}
    
    ~ExactAbsMatchersRunner() {
        delete _efmAbs0Ptr;
        delete _efmAbs1Ptr;
        delete _efmAbs2Ptr;
        delete _efmAbs3Ptr;
        delete _efmAbs4Ptr;
        delete _efmAbs5Ptr;
        delete _efmAbs6Ptr;
        delete _efmAbs7Ptr;
        delete _efmAbs8Ptr;
        delete _efmAbs9Ptr;
        delete _efmAbs10Ptr;
        delete _efmAbs11Ptr;
        delete _efmAbs12Ptr;
        delete _efmAbs13Ptr;
        delete _efmAbs14Ptr;
        delete _efmAbs15Ptr;
        delete _efmAbs16Ptr;
        delete _efmAbs17Ptr;
        delete _efmAbs18Ptr;
        delete _efmAbs19Ptr;
        delete _efmAbs20Ptr;
        delete _efmAbs21Ptr;
        delete _efmAbs22Ptr;
        delete _efmAbs23Ptr;
        delete _efmAbs24Ptr;
        delete _efmAbs25Ptr;
        delete _efmAbs26Ptr;
        delete _efmAbs27Ptr;
        delete _efmAbs28Ptr;
        delete _efmAbs29Ptr;
        delete _efmAbs30Ptr;
        delete _efmAbs31Ptr;
        delete _efmAbs32Ptr;
        delete _efmAbs33Ptr;
        delete _efmAbs34Ptr;
        delete _efmAbs35Ptr;
        delete _efmAbs36Ptr;
        delete _efmAbs37Ptr;
        delete _efmAbs38Ptr;
        delete _efmAbs39Ptr;
        delete _efmAbs40Ptr;
        delete _efmAbs41Ptr;
        delete _efmAbs42Ptr;
        delete _efmAbs43Ptr;
        delete _efmAbs44Ptr;
        delete _efmAbs45Ptr;
        delete _efmAbs46Ptr;
        delete _efmAbs47Ptr;
        delete _efmAbs48Ptr;
        delete _efmAbs49Ptr;
        delete _efmAbs50Ptr;
        delete _efmAbs100Ptr;
    }  
    
    void init(int thresh,int imWidthStep, IplImage* pattern, std::vector<Point> maskLocations)
    {
    	_thresh= thresh;
    	
        switch (thresh) {
        case 0:
            _efmAbs0Ptr= new T_ABS0(imWidthStep,pattern,maskLocations);  break;
        case 1:
            _efmAbs1Ptr= new T_ABS1(imWidthStep,pattern,maskLocations);  break;
        case 2:
            _efmAbs2Ptr= new T_ABS2(imWidthStep,pattern,maskLocations);  break;
        case 3:
            _efmAbs3Ptr= new T_ABS3(imWidthStep,pattern,maskLocations);  break;
        case 4:
            _efmAbs4Ptr= new T_ABS4(imWidthStep,pattern,maskLocations);  break;
        case 5:
            _efmAbs5Ptr= new T_ABS5(imWidthStep,pattern,maskLocations);  break;
        case 6:
            _efmAbs6Ptr= new T_ABS6(imWidthStep,pattern,maskLocations);  break;
        case 7:
            _efmAbs7Ptr= new T_ABS7(imWidthStep,pattern,maskLocations);  break;
        case 8:
            _efmAbs8Ptr= new T_ABS8(imWidthStep,pattern,maskLocations);  break;
        case 9:
            _efmAbs9Ptr= new T_ABS9(imWidthStep,pattern,maskLocations);  break;
        case 10:
            _efmAbs10Ptr= new T_ABS10(imWidthStep,pattern,maskLocations);  break;
        case 11:
            _efmAbs11Ptr= new T_ABS11(imWidthStep,pattern,maskLocations);  break;
        case 12:
            _efmAbs12Ptr= new T_ABS12(imWidthStep,pattern,maskLocations);  break;
        case 13:
            _efmAbs13Ptr= new T_ABS13(imWidthStep,pattern,maskLocations);  break;
        case 14:
            _efmAbs14Ptr= new T_ABS14(imWidthStep,pattern,maskLocations);  break;
        case 15:
            _efmAbs15Ptr= new T_ABS15(imWidthStep,pattern,maskLocations);  break;
        case 16:
            _efmAbs16Ptr= new T_ABS16(imWidthStep,pattern,maskLocations);  break;
        case 17:
            _efmAbs17Ptr= new T_ABS17(imWidthStep,pattern,maskLocations);  break;
        case 18:
            _efmAbs18Ptr= new T_ABS18(imWidthStep,pattern,maskLocations);  break;
        case 19:
            _efmAbs19Ptr= new T_ABS19(imWidthStep,pattern,maskLocations);  break;
        case 20:
            _efmAbs20Ptr= new T_ABS20(imWidthStep,pattern,maskLocations);  break;
        case 21:
            _efmAbs21Ptr= new T_ABS21(imWidthStep,pattern,maskLocations);  break;
        case 22:
            _efmAbs22Ptr= new T_ABS22(imWidthStep,pattern,maskLocations);  break;
        case 23:
            _efmAbs23Ptr= new T_ABS23(imWidthStep,pattern,maskLocations);  break;
        case 24:
            _efmAbs24Ptr= new T_ABS24(imWidthStep,pattern,maskLocations);  break;
        case 25:
            _efmAbs25Ptr= new T_ABS25(imWidthStep,pattern,maskLocations);  break;
        case 26:
            _efmAbs26Ptr= new T_ABS26(imWidthStep,pattern,maskLocations);  break;
        case 27:
            _efmAbs27Ptr= new T_ABS27(imWidthStep,pattern,maskLocations);  break;
        case 28:
            _efmAbs28Ptr= new T_ABS28(imWidthStep,pattern,maskLocations);  break;
        case 29:
            _efmAbs29Ptr= new T_ABS29(imWidthStep,pattern,maskLocations);  break;
        case 30:
            _efmAbs30Ptr= new T_ABS30(imWidthStep,pattern,maskLocations);  break;
        case 31:
            _efmAbs31Ptr= new T_ABS31(imWidthStep,pattern,maskLocations);  break;
        case 32:
            _efmAbs32Ptr= new T_ABS32(imWidthStep,pattern,maskLocations);  break;
        case 33:
            _efmAbs33Ptr= new T_ABS33(imWidthStep,pattern,maskLocations);  break;
        case 34:
            _efmAbs34Ptr= new T_ABS34(imWidthStep,pattern,maskLocations);  break;
        case 35:
            _efmAbs35Ptr= new T_ABS35(imWidthStep,pattern,maskLocations);  break;
        case 36:
            _efmAbs36Ptr= new T_ABS36(imWidthStep,pattern,maskLocations);  break;
        case 37:
            _efmAbs37Ptr= new T_ABS37(imWidthStep,pattern,maskLocations);  break;
        case 38:
            _efmAbs38Ptr= new T_ABS38(imWidthStep,pattern,maskLocations);  break;
        case 39:
            _efmAbs39Ptr= new T_ABS39(imWidthStep,pattern,maskLocations);  break;
        case 40:
            _efmAbs40Ptr= new T_ABS40(imWidthStep,pattern,maskLocations);  break;
        case 41:
            _efmAbs41Ptr= new T_ABS41(imWidthStep,pattern,maskLocations);  break;
        case 42:
            _efmAbs42Ptr= new T_ABS42(imWidthStep,pattern,maskLocations);  break;
        case 43:
            _efmAbs43Ptr= new T_ABS43(imWidthStep,pattern,maskLocations);  break;
        case 44:
            _efmAbs44Ptr= new T_ABS44(imWidthStep,pattern,maskLocations);  break;
        case 45:
            _efmAbs45Ptr= new T_ABS45(imWidthStep,pattern,maskLocations);  break;
        case 46:
            _efmAbs46Ptr= new T_ABS46(imWidthStep,pattern,maskLocations);  break;
        case 47:
            _efmAbs47Ptr= new T_ABS47(imWidthStep,pattern,maskLocations);  break;
        case 48:
            _efmAbs48Ptr= new T_ABS48(imWidthStep,pattern,maskLocations);  break;
        case 49:
            _efmAbs49Ptr= new T_ABS49(imWidthStep,pattern,maskLocations);  break;
        case 50:
            _efmAbs50Ptr= new T_ABS50(imWidthStep,pattern,maskLocations);  break;
        case 100:
            _efmAbs100Ptr= new T_ABS100(imWidthStep,pattern,maskLocations);  break;
            
        default:
            // Should never get here
            assert(false);
            
        } // end switch
        
    } // end init
    
    
    void match(IplImage* image, CvMat* result) {
        switch (_thresh) {
        case 0:
            _efmAbs0Ptr->cvHammingMatchTemplate(image,result);  break;
        case 1:
            _efmAbs1Ptr->cvHammingMatchTemplate(image,result);  break;
        case 2:
            _efmAbs2Ptr->cvHammingMatchTemplate(image,result);  break;
        case 3:
            _efmAbs3Ptr->cvHammingMatchTemplate(image,result);  break;
        case 4:
            _efmAbs4Ptr->cvHammingMatchTemplate(image,result);  break;
        case 5:
            _efmAbs5Ptr->cvHammingMatchTemplate(image,result);  break;
        case 6:
            _efmAbs6Ptr->cvHammingMatchTemplate(image,result);  break;
        case 7:
            _efmAbs7Ptr->cvHammingMatchTemplate(image,result);  break;
        case 8:
            _efmAbs8Ptr->cvHammingMatchTemplate(image,result);  break;
        case 9:
            _efmAbs9Ptr->cvHammingMatchTemplate(image,result);  break;
        case 10:
            _efmAbs10Ptr->cvHammingMatchTemplate(image,result);  break;
        case 11:
            _efmAbs11Ptr->cvHammingMatchTemplate(image,result);  break;
        case 12:
            _efmAbs12Ptr->cvHammingMatchTemplate(image,result);  break;
        case 13:
            _efmAbs13Ptr->cvHammingMatchTemplate(image,result);  break;
        case 14:
            _efmAbs14Ptr->cvHammingMatchTemplate(image,result);  break;
        case 15:
            _efmAbs15Ptr->cvHammingMatchTemplate(image,result);  break;
        case 16:
            _efmAbs16Ptr->cvHammingMatchTemplate(image,result);  break;
        case 17:
            _efmAbs17Ptr->cvHammingMatchTemplate(image,result);  break;
        case 18:
            _efmAbs18Ptr->cvHammingMatchTemplate(image,result);  break;
        case 19:
            _efmAbs19Ptr->cvHammingMatchTemplate(image,result);  break;
        case 20:
            _efmAbs20Ptr->cvHammingMatchTemplate(image,result);  break;
        case 21:
            _efmAbs21Ptr->cvHammingMatchTemplate(image,result);  break;
        case 22:
            _efmAbs22Ptr->cvHammingMatchTemplate(image,result);  break;
        case 23:
            _efmAbs23Ptr->cvHammingMatchTemplate(image,result);  break;
        case 24:
            _efmAbs24Ptr->cvHammingMatchTemplate(image,result);  break;
        case 25:
            _efmAbs25Ptr->cvHammingMatchTemplate(image,result);  break;
        case 26:
            _efmAbs26Ptr->cvHammingMatchTemplate(image,result);  break;
        case 27:
            _efmAbs27Ptr->cvHammingMatchTemplate(image,result);  break;
        case 28:
            _efmAbs28Ptr->cvHammingMatchTemplate(image,result);  break;
        case 29:
            _efmAbs29Ptr->cvHammingMatchTemplate(image,result);  break;
        case 30:
            _efmAbs30Ptr->cvHammingMatchTemplate(image,result);  break;
        case 31:
            _efmAbs31Ptr->cvHammingMatchTemplate(image,result);  break;
        case 32:
            _efmAbs32Ptr->cvHammingMatchTemplate(image,result);  break;
        case 33:
            _efmAbs33Ptr->cvHammingMatchTemplate(image,result);  break;
        case 34:
            _efmAbs34Ptr->cvHammingMatchTemplate(image,result);  break;
        case 35:
            _efmAbs35Ptr->cvHammingMatchTemplate(image,result);  break;
        case 36:
            _efmAbs36Ptr->cvHammingMatchTemplate(image,result);  break;
        case 37:
            _efmAbs37Ptr->cvHammingMatchTemplate(image,result);  break;
        case 38:
            _efmAbs38Ptr->cvHammingMatchTemplate(image,result);  break;
        case 39:
            _efmAbs39Ptr->cvHammingMatchTemplate(image,result);  break;
        case 40:
            _efmAbs40Ptr->cvHammingMatchTemplate(image,result);  break;
        case 41:
            _efmAbs41Ptr->cvHammingMatchTemplate(image,result);  break;
        case 42:
            _efmAbs42Ptr->cvHammingMatchTemplate(image,result);  break;
        case 43:
            _efmAbs43Ptr->cvHammingMatchTemplate(image,result);  break;
        case 44:
            _efmAbs44Ptr->cvHammingMatchTemplate(image,result);  break;
        case 45:
            _efmAbs45Ptr->cvHammingMatchTemplate(image,result);  break;
        case 46:
            _efmAbs46Ptr->cvHammingMatchTemplate(image,result);  break;
        case 47:
            _efmAbs47Ptr->cvHammingMatchTemplate(image,result);  break;
        case 48:
            _efmAbs48Ptr->cvHammingMatchTemplate(image,result);  break;
        case 49:
            _efmAbs49Ptr->cvHammingMatchTemplate(image,result);  break;
        case 50:
            _efmAbs50Ptr->cvHammingMatchTemplate(image,result);  break;
        case 100:
            _efmAbs100Ptr->cvHammingMatchTemplate(image,result);  break;
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
