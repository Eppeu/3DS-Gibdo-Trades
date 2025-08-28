#include "modding.h"
#include "global.h"
#include "eztr_api.h"
#include "z64player.h"
#include "z64item.h"

RECOMP_IMPORT("*", u32 recomp_get_config_u32(const char *key));

typedef struct {
    /* 0x0 */ PlayerItemAction itemAction;
    /* 0x4 */ ItemId item;
    /* 0x8 */ s32 amount;
    /* 0xC */ s16 isBottledItem;
} EnTalkGibudRequestedItem; // size = 0x10


typedef enum
{
    RedPotion,
    BluePotion,
} GibdoTradePotion;
#define ALTERNATIVE_GIBDO_POTION ((GibdoTradePotion)recomp_get_config_u32("custom_potion_gibdo"))

extern EnTalkGibudRequestedItem sRequestedItemTable[];

RECOMP_CALLBACK("*",recomp_on_play_main)
void EditGibdoTrades(PlayState* play)
{
    if (ALTERNATIVE_GIBDO_POTION == RedPotion)
    {
    sRequestedItemTable[0].itemAction = PLAYER_IA_BOTTLE_POTION_RED;
    sRequestedItemTable[0].item = ITEM_POTION_RED;
    }
    else
    {
    sRequestedItemTable[0].itemAction = PLAYER_IA_BOTTLE_POTION_BLUE;
    sRequestedItemTable[0].item = ITEM_POTION_BLUE;    
    }
    sRequestedItemTable[1].amount = 1;
    sRequestedItemTable[5].amount = 1;
    sRequestedItemTable[6].amount = 1;
}
EZTR_ON_INIT void threeds_gibdo_messages()
{
EZTR_Basic_ReplaceText(
    0x138C,
    EZTR_STANDARD_TEXT_BOX_I,
    0,
    EZTR_ICON_NO_ICON,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    false,
    "Leeeave me some medicine that" EZTR_CC_NEWLINE "bestows health!" EZTR_CC_EVENT "" EZTR_CC_END "",
    NULL
);    

EZTR_Basic_ReplaceText(
    0x138D,
    EZTR_STANDARD_TEXT_BOX_I,
    0,
    EZTR_ICON_NO_ICON,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    false,
    "Leeeave me something crunchy that" EZTR_CC_NEWLINE "that sprouts leaves when watered!" EZTR_CC_EVENT "" EZTR_CC_END "",
    NULL
);

EZTR_Basic_ReplaceText(
    0x1391,
    EZTR_STANDARD_TEXT_BOX_I,
    0,
    EZTR_ICON_NO_ICON,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    false,
    "Leeeaave me something that flashes" EZTR_CC_NEWLINE "brightly and can also be dropped" EZTR_CC_NEWLINE "like a bomb." EZTR_CC_EVENT "" EZTR_CC_END "",
    NULL
);

EZTR_Basic_ReplaceText(
    0x1392,
    EZTR_STANDARD_TEXT_BOX_I,
    0,
    EZTR_ICON_NO_ICON,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    EZTR_NO_VALUE,
    false,
    "Leeeaave me something that" EZTR_CC_NEWLINE "goes boom!" EZTR_CC_EVENT "" EZTR_CC_END "",
    NULL
);
}