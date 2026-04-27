#ifndef STM8_COMP_COMPAT_H
#define STM8_COMP_COMPAT_H

#ifdef __VSCODE_INTELLISENSE__
    /* Ми не можемо задефайнити '@', бо це заборонено стандартом C.
       Але ми можемо оголосити типи, які "зламалися" через цей символ.
    */
    
    // Це виправить помилку "identifier interrupt_handler_t is undefined"
    typedef void (*interrupt_handler_t)(void); 

    // Це допоможе з функцією стартапу
    extern void _stext(void);

    // Маскуємо інші слова (без символа @)
    #define far
    #define near
    #define tiny
    #define interrupt
#endif

#endif