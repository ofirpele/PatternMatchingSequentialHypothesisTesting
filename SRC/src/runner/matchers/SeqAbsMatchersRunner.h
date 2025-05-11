#ifndef SEQABSMATCHERSRUNNER_H_
#define SEQABSMATCHERSRUNNER_H_

#include <SeqFastMatcher.h>
#include <isSimilar/DiffAbs_IsSimilar_uchar.h>

class SeqAbsMatchersRunner {

private:
    
    int _thresh;
    
    typedef DiffAbs_IsSimilar_uchar<0> T_TABS0;
    typedef SeqFastMatcher<T_TABS0> T_ABS0;
    T_ABS0* _sfmAbs0Ptr;
    typedef DiffAbs_IsSimilar_uchar<1> T_TABS1;
    typedef SeqFastMatcher<T_TABS1> T_ABS1;
    T_ABS1* _sfmAbs1Ptr;
    typedef DiffAbs_IsSimilar_uchar<2> T_TABS2;
    typedef SeqFastMatcher<T_TABS2> T_ABS2;
    T_ABS2* _sfmAbs2Ptr;
    typedef DiffAbs_IsSimilar_uchar<3> T_TABS3;
    typedef SeqFastMatcher<T_TABS3> T_ABS3;
    T_ABS3* _sfmAbs3Ptr;
    typedef DiffAbs_IsSimilar_uchar<4> T_TABS4;
    typedef SeqFastMatcher<T_TABS4> T_ABS4;
    T_ABS4* _sfmAbs4Ptr;
    typedef DiffAbs_IsSimilar_uchar<5> T_TABS5;
    typedef SeqFastMatcher<T_TABS5> T_ABS5;
    T_ABS5* _sfmAbs5Ptr;
    typedef DiffAbs_IsSimilar_uchar<6> T_TABS6;
    typedef SeqFastMatcher<T_TABS6> T_ABS6;
    T_ABS6* _sfmAbs6Ptr;
    typedef DiffAbs_IsSimilar_uchar<7> T_TABS7;
    typedef SeqFastMatcher<T_TABS7> T_ABS7;
    T_ABS7* _sfmAbs7Ptr;
    typedef DiffAbs_IsSimilar_uchar<8> T_TABS8;
    typedef SeqFastMatcher<T_TABS8> T_ABS8;
    T_ABS8* _sfmAbs8Ptr;
    typedef DiffAbs_IsSimilar_uchar<9> T_TABS9;
    typedef SeqFastMatcher<T_TABS9> T_ABS9;
    T_ABS9* _sfmAbs9Ptr;
    typedef DiffAbs_IsSimilar_uchar<10> T_TABS10;
    typedef SeqFastMatcher<T_TABS10> T_ABS10;
    T_ABS10* _sfmAbs10Ptr;
    typedef DiffAbs_IsSimilar_uchar<11> T_TABS11;
    typedef SeqFastMatcher<T_TABS11> T_ABS11;
    T_ABS11* _sfmAbs11Ptr;
    typedef DiffAbs_IsSimilar_uchar<12> T_TABS12;
    typedef SeqFastMatcher<T_TABS12> T_ABS12;
    T_ABS12* _sfmAbs12Ptr;
    typedef DiffAbs_IsSimilar_uchar<13> T_TABS13;
    typedef SeqFastMatcher<T_TABS13> T_ABS13;
    T_ABS13* _sfmAbs13Ptr;
    typedef DiffAbs_IsSimilar_uchar<14> T_TABS14;
    typedef SeqFastMatcher<T_TABS14> T_ABS14;
    T_ABS14* _sfmAbs14Ptr;
    typedef DiffAbs_IsSimilar_uchar<15> T_TABS15;
    typedef SeqFastMatcher<T_TABS15> T_ABS15;
    T_ABS15* _sfmAbs15Ptr;
    typedef DiffAbs_IsSimilar_uchar<16> T_TABS16;
    typedef SeqFastMatcher<T_TABS16> T_ABS16;
    T_ABS16* _sfmAbs16Ptr;
    typedef DiffAbs_IsSimilar_uchar<17> T_TABS17;
    typedef SeqFastMatcher<T_TABS17> T_ABS17;
    T_ABS17* _sfmAbs17Ptr;
    typedef DiffAbs_IsSimilar_uchar<18> T_TABS18;
    typedef SeqFastMatcher<T_TABS18> T_ABS18;
    T_ABS18* _sfmAbs18Ptr;
    typedef DiffAbs_IsSimilar_uchar<19> T_TABS19;
    typedef SeqFastMatcher<T_TABS19> T_ABS19;
    T_ABS19* _sfmAbs19Ptr;
    typedef DiffAbs_IsSimilar_uchar<20> T_TABS20;
    typedef SeqFastMatcher<T_TABS20> T_ABS20;
    T_ABS20* _sfmAbs20Ptr;
    typedef DiffAbs_IsSimilar_uchar<21> T_TABS21;
    typedef SeqFastMatcher<T_TABS21> T_ABS21;
    T_ABS21* _sfmAbs21Ptr;
    typedef DiffAbs_IsSimilar_uchar<22> T_TABS22;
    typedef SeqFastMatcher<T_TABS22> T_ABS22;
    T_ABS22* _sfmAbs22Ptr;
    typedef DiffAbs_IsSimilar_uchar<23> T_TABS23;
    typedef SeqFastMatcher<T_TABS23> T_ABS23;
    T_ABS23* _sfmAbs23Ptr;
    typedef DiffAbs_IsSimilar_uchar<24> T_TABS24;
    typedef SeqFastMatcher<T_TABS24> T_ABS24;
    T_ABS24* _sfmAbs24Ptr;
    typedef DiffAbs_IsSimilar_uchar<25> T_TABS25;
    typedef SeqFastMatcher<T_TABS25> T_ABS25;
    T_ABS25* _sfmAbs25Ptr;
    typedef DiffAbs_IsSimilar_uchar<26> T_TABS26;
    typedef SeqFastMatcher<T_TABS26> T_ABS26;
    T_ABS26* _sfmAbs26Ptr;
    typedef DiffAbs_IsSimilar_uchar<27> T_TABS27;
    typedef SeqFastMatcher<T_TABS27> T_ABS27;
    T_ABS27* _sfmAbs27Ptr;
    typedef DiffAbs_IsSimilar_uchar<28> T_TABS28;
    typedef SeqFastMatcher<T_TABS28> T_ABS28;
    T_ABS28* _sfmAbs28Ptr;
    typedef DiffAbs_IsSimilar_uchar<29> T_TABS29;
    typedef SeqFastMatcher<T_TABS29> T_ABS29;
    T_ABS29* _sfmAbs29Ptr;
    typedef DiffAbs_IsSimilar_uchar<30> T_TABS30;
    typedef SeqFastMatcher<T_TABS30> T_ABS30;
    T_ABS30* _sfmAbs30Ptr;
    typedef DiffAbs_IsSimilar_uchar<31> T_TABS31;
    typedef SeqFastMatcher<T_TABS31> T_ABS31;
    T_ABS31* _sfmAbs31Ptr;
    typedef DiffAbs_IsSimilar_uchar<32> T_TABS32;
    typedef SeqFastMatcher<T_TABS32> T_ABS32;
    T_ABS32* _sfmAbs32Ptr;
    typedef DiffAbs_IsSimilar_uchar<33> T_TABS33;
    typedef SeqFastMatcher<T_TABS33> T_ABS33;
    T_ABS33* _sfmAbs33Ptr;
    typedef DiffAbs_IsSimilar_uchar<34> T_TABS34;
    typedef SeqFastMatcher<T_TABS34> T_ABS34;
    T_ABS34* _sfmAbs34Ptr;
    typedef DiffAbs_IsSimilar_uchar<35> T_TABS35;
    typedef SeqFastMatcher<T_TABS35> T_ABS35;
    T_ABS35* _sfmAbs35Ptr;
    typedef DiffAbs_IsSimilar_uchar<36> T_TABS36;
    typedef SeqFastMatcher<T_TABS36> T_ABS36;
    T_ABS36* _sfmAbs36Ptr;
    typedef DiffAbs_IsSimilar_uchar<37> T_TABS37;
    typedef SeqFastMatcher<T_TABS37> T_ABS37;
    T_ABS37* _sfmAbs37Ptr;
    typedef DiffAbs_IsSimilar_uchar<38> T_TABS38;
    typedef SeqFastMatcher<T_TABS38> T_ABS38;
    T_ABS38* _sfmAbs38Ptr;
    typedef DiffAbs_IsSimilar_uchar<39> T_TABS39;
    typedef SeqFastMatcher<T_TABS39> T_ABS39;
    T_ABS39* _sfmAbs39Ptr;
    typedef DiffAbs_IsSimilar_uchar<40> T_TABS40;
    typedef SeqFastMatcher<T_TABS40> T_ABS40;
    T_ABS40* _sfmAbs40Ptr;
    typedef DiffAbs_IsSimilar_uchar<41> T_TABS41;
    typedef SeqFastMatcher<T_TABS41> T_ABS41;
    T_ABS41* _sfmAbs41Ptr;
    typedef DiffAbs_IsSimilar_uchar<42> T_TABS42;
    typedef SeqFastMatcher<T_TABS42> T_ABS42;
    T_ABS42* _sfmAbs42Ptr;
    typedef DiffAbs_IsSimilar_uchar<43> T_TABS43;
    typedef SeqFastMatcher<T_TABS43> T_ABS43;
    T_ABS43* _sfmAbs43Ptr;
    typedef DiffAbs_IsSimilar_uchar<44> T_TABS44;
    typedef SeqFastMatcher<T_TABS44> T_ABS44;
    T_ABS44* _sfmAbs44Ptr;
    typedef DiffAbs_IsSimilar_uchar<45> T_TABS45;
    typedef SeqFastMatcher<T_TABS45> T_ABS45;
    T_ABS45* _sfmAbs45Ptr;
    typedef DiffAbs_IsSimilar_uchar<46> T_TABS46;
    typedef SeqFastMatcher<T_TABS46> T_ABS46;
    T_ABS46* _sfmAbs46Ptr;
    typedef DiffAbs_IsSimilar_uchar<47> T_TABS47;
    typedef SeqFastMatcher<T_TABS47> T_ABS47;
    T_ABS47* _sfmAbs47Ptr;
    typedef DiffAbs_IsSimilar_uchar<48> T_TABS48;
    typedef SeqFastMatcher<T_TABS48> T_ABS48;
    T_ABS48* _sfmAbs48Ptr;
    typedef DiffAbs_IsSimilar_uchar<49> T_TABS49;
    typedef SeqFastMatcher<T_TABS49> T_ABS49;
    T_ABS49* _sfmAbs49Ptr;
    typedef DiffAbs_IsSimilar_uchar<50> T_TABS50;
    typedef SeqFastMatcher<T_TABS50> T_ABS50;
    T_ABS50* _sfmAbs50Ptr;
    typedef DiffAbs_IsSimilar_uchar<100> T_TABS100;
    typedef SeqFastMatcher<T_TABS100> T_ABS100;
    T_ABS100* _sfmAbs100Ptr;
        
    
public:    
            
    SeqAbsMatchersRunner() 
        : 
        _sfmAbs0Ptr(NULL),
            _sfmAbs1Ptr(NULL),
            _sfmAbs2Ptr(NULL),
            _sfmAbs3Ptr(NULL),
            _sfmAbs4Ptr(NULL),
            _sfmAbs5Ptr(NULL),
            _sfmAbs6Ptr(NULL),
            _sfmAbs7Ptr(NULL),
            _sfmAbs8Ptr(NULL),
            _sfmAbs9Ptr(NULL),
            _sfmAbs10Ptr(NULL),
            _sfmAbs11Ptr(NULL),
            _sfmAbs12Ptr(NULL),
            _sfmAbs13Ptr(NULL),
            _sfmAbs14Ptr(NULL),
            _sfmAbs15Ptr(NULL),
            _sfmAbs16Ptr(NULL),
            _sfmAbs17Ptr(NULL),
            _sfmAbs18Ptr(NULL),
            _sfmAbs19Ptr(NULL),
            _sfmAbs20Ptr(NULL),
            _sfmAbs21Ptr(NULL),
            _sfmAbs22Ptr(NULL),
            _sfmAbs23Ptr(NULL),
            _sfmAbs24Ptr(NULL),
            _sfmAbs25Ptr(NULL),
            _sfmAbs26Ptr(NULL),
            _sfmAbs27Ptr(NULL),
            _sfmAbs28Ptr(NULL),
            _sfmAbs29Ptr(NULL),
            _sfmAbs30Ptr(NULL),
            _sfmAbs31Ptr(NULL),
            _sfmAbs32Ptr(NULL),
            _sfmAbs33Ptr(NULL),
            _sfmAbs34Ptr(NULL),
            _sfmAbs35Ptr(NULL),
            _sfmAbs36Ptr(NULL),
            _sfmAbs37Ptr(NULL),
            _sfmAbs38Ptr(NULL),
            _sfmAbs39Ptr(NULL),
            _sfmAbs40Ptr(NULL),
            _sfmAbs41Ptr(NULL),
            _sfmAbs42Ptr(NULL),
            _sfmAbs43Ptr(NULL),
            _sfmAbs44Ptr(NULL),
            _sfmAbs45Ptr(NULL),
            _sfmAbs46Ptr(NULL),
            _sfmAbs47Ptr(NULL),
            _sfmAbs48Ptr(NULL),
            _sfmAbs49Ptr(NULL),
            _sfmAbs50Ptr(NULL),
            _sfmAbs100Ptr(NULL)
            {}
    
    ~SeqAbsMatchersRunner() {
        delete _sfmAbs0Ptr;
        delete _sfmAbs1Ptr;
        delete _sfmAbs2Ptr;
        delete _sfmAbs3Ptr;
        delete _sfmAbs4Ptr;
        delete _sfmAbs5Ptr;
        delete _sfmAbs6Ptr;
        delete _sfmAbs7Ptr;
        delete _sfmAbs8Ptr;
        delete _sfmAbs9Ptr;
        delete _sfmAbs10Ptr;
        delete _sfmAbs11Ptr;
        delete _sfmAbs12Ptr;
        delete _sfmAbs13Ptr;
        delete _sfmAbs14Ptr;
        delete _sfmAbs15Ptr;
        delete _sfmAbs16Ptr;
        delete _sfmAbs17Ptr;
        delete _sfmAbs18Ptr;
        delete _sfmAbs19Ptr;
        delete _sfmAbs20Ptr;
        delete _sfmAbs21Ptr;
        delete _sfmAbs22Ptr;
        delete _sfmAbs23Ptr;
        delete _sfmAbs24Ptr;
        delete _sfmAbs25Ptr;
        delete _sfmAbs26Ptr;
        delete _sfmAbs27Ptr;
        delete _sfmAbs28Ptr;
        delete _sfmAbs29Ptr;
        delete _sfmAbs30Ptr;
        delete _sfmAbs31Ptr;
        delete _sfmAbs32Ptr;
        delete _sfmAbs33Ptr;
        delete _sfmAbs34Ptr;
        delete _sfmAbs35Ptr;
        delete _sfmAbs36Ptr;
        delete _sfmAbs37Ptr;
        delete _sfmAbs38Ptr;
        delete _sfmAbs39Ptr;
        delete _sfmAbs40Ptr;
        delete _sfmAbs41Ptr;
        delete _sfmAbs42Ptr;
        delete _sfmAbs43Ptr;
        delete _sfmAbs44Ptr;
        delete _sfmAbs45Ptr;
        delete _sfmAbs46Ptr;
        delete _sfmAbs47Ptr;
        delete _sfmAbs48Ptr;
        delete _sfmAbs49Ptr;
        delete _sfmAbs50Ptr;
        delete _sfmAbs100Ptr;
    }  
    
    void init(int thresh,int imWidthStep, IplImage* pattern, std::vector<Point> maskLocations,
        const double& falseNegative, const double& maxOcclusion)
    {
    	_thresh= thresh;
    	
        switch (thresh) {
        case 0:
            _sfmAbs0Ptr= new T_ABS0(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 1:
            _sfmAbs1Ptr= new T_ABS1(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 2:
            _sfmAbs2Ptr= new T_ABS2(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 3:
            _sfmAbs3Ptr= new T_ABS3(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 4:
            _sfmAbs4Ptr= new T_ABS4(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 5:
            _sfmAbs5Ptr= new T_ABS5(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 6:
            _sfmAbs6Ptr= new T_ABS6(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 7:
            _sfmAbs7Ptr= new T_ABS7(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 8:
            _sfmAbs8Ptr= new T_ABS8(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 9:
            _sfmAbs9Ptr= new T_ABS9(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 10:
            _sfmAbs10Ptr= new T_ABS10(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 11:
            _sfmAbs11Ptr= new T_ABS11(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 12:
            _sfmAbs12Ptr= new T_ABS12(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 13:
            _sfmAbs13Ptr= new T_ABS13(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 14:
            _sfmAbs14Ptr= new T_ABS14(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 15:
            _sfmAbs15Ptr= new T_ABS15(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 16:
            _sfmAbs16Ptr= new T_ABS16(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 17:
            _sfmAbs17Ptr= new T_ABS17(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 18:
            _sfmAbs18Ptr= new T_ABS18(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 19:
            _sfmAbs19Ptr= new T_ABS19(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 20:
            _sfmAbs20Ptr= new T_ABS20(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 21:
            _sfmAbs21Ptr= new T_ABS21(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 22:
            _sfmAbs22Ptr= new T_ABS22(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 23:
            _sfmAbs23Ptr= new T_ABS23(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 24:
            _sfmAbs24Ptr= new T_ABS24(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 25:
            _sfmAbs25Ptr= new T_ABS25(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 26:
            _sfmAbs26Ptr= new T_ABS26(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 27:
            _sfmAbs27Ptr= new T_ABS27(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 28:
            _sfmAbs28Ptr= new T_ABS28(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 29:
            _sfmAbs29Ptr= new T_ABS29(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 30:
            _sfmAbs30Ptr= new T_ABS30(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 31:
            _sfmAbs31Ptr= new T_ABS31(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 32:
            _sfmAbs32Ptr= new T_ABS32(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 33:
            _sfmAbs33Ptr= new T_ABS33(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 34:
            _sfmAbs34Ptr= new T_ABS34(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 35:
            _sfmAbs35Ptr= new T_ABS35(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 36:
            _sfmAbs36Ptr= new T_ABS36(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 37:
            _sfmAbs37Ptr= new T_ABS37(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 38:
            _sfmAbs38Ptr= new T_ABS38(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 39:
            _sfmAbs39Ptr= new T_ABS39(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 40:
            _sfmAbs40Ptr= new T_ABS40(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 41:
            _sfmAbs41Ptr= new T_ABS41(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 42:
            _sfmAbs42Ptr= new T_ABS42(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 43:
            _sfmAbs43Ptr= new T_ABS43(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 44:
            _sfmAbs44Ptr= new T_ABS44(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 45:
            _sfmAbs45Ptr= new T_ABS45(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 46:
            _sfmAbs46Ptr= new T_ABS46(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 47:
            _sfmAbs47Ptr= new T_ABS47(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 48:
            _sfmAbs48Ptr= new T_ABS48(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 49:
            _sfmAbs49Ptr= new T_ABS49(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 50:
            _sfmAbs50Ptr= new T_ABS50(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        case 100:
            _sfmAbs100Ptr= new T_ABS100(imWidthStep,pattern,maskLocations,falseNegative,maxOcclusion);  break;
        default:
            // Should never get here
            assert(false);
            
        } // end switch
        
    } // end init
    
    
    void match(IplImage* image, CvMat* result) {
        switch (_thresh) {
        case 0:
            _sfmAbs0Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 1:
            _sfmAbs1Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 2:
            _sfmAbs2Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 3:
            _sfmAbs3Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 4:
            _sfmAbs4Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 5:
            _sfmAbs5Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 6:
            _sfmAbs6Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 7:
            _sfmAbs7Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 8:
            _sfmAbs8Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 9:
            _sfmAbs9Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 10:
            _sfmAbs10Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 11:
            _sfmAbs11Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 12:
            _sfmAbs12Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 13:
            _sfmAbs13Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 14:
            _sfmAbs14Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 15:
            _sfmAbs15Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 16:
            _sfmAbs16Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 17:
            _sfmAbs17Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 18:
            _sfmAbs18Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 19:
            _sfmAbs19Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 20:
            _sfmAbs20Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 21:
            _sfmAbs21Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 22:
            _sfmAbs22Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 23:
            _sfmAbs23Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 24:
            _sfmAbs24Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 25:
            _sfmAbs25Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 26:
            _sfmAbs26Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 27:
            _sfmAbs27Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 28:
            _sfmAbs28Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 29:
            _sfmAbs29Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 30:
            _sfmAbs30Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 31:
            _sfmAbs31Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 32:
            _sfmAbs32Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 33:
            _sfmAbs33Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 34:
            _sfmAbs34Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 35:
            _sfmAbs35Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 36:
            _sfmAbs36Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 37:
            _sfmAbs37Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 38:
            _sfmAbs38Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 39:
            _sfmAbs39Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 40:
            _sfmAbs40Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 41:
            _sfmAbs41Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 42:
            _sfmAbs42Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 43:
            _sfmAbs43Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 44:
            _sfmAbs44Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 45:
            _sfmAbs45Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 46:
            _sfmAbs46Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 47:
            _sfmAbs47Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 48:
            _sfmAbs48Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 49:
            _sfmAbs49Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 50:
            _sfmAbs50Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
        case 100:
            _sfmAbs100Ptr->cvHammingSamplingMatchTemplate(image,result);  break;
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
