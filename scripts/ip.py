# =================================================================================
# file :   ip.py
# brief :  Instantiate and configure a LiteX IP.
#
# author : l.heywang <leonard.heywang@proton.me>
# date :   27/06/2026
# 
# copyright : MIT 
# =================================================================================

def instantiante(SoC, Platform, Environement) -> int:
    """
        Instantiate a new IP within the SoC.

        Arguments : 
            Soc :           The base SoC system.
            Platform :      The Platform with all definitions.
            Environement :  The environment to be passed.

        Returns : 
            Int :           Return code. 
                0           OK
                !0          ERROR
    """
    print("[ IP NAME ] LiteX not supported.")
    return 0