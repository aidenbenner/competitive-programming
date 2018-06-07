class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """


        num = numerator
        dem = denominator

        sign = ""
        if num * dem < 0:
            sign = "-"
        num = abs(num)
        dem = abs(dem)

        q = num // dem
        r = num % dem


        if r == 0:
            return sign + str(q)

        repeat = False
        mp = {}


        def longDiv(num, dem):
            if (num, dem) in mp:
                mp[(num, dem)] = True
                return ")"

            mp[(num, dem)] = False
            q = num // dem
            r = num % dem

            if r == 0:
                return str(q)
            rem = longDiv(10 * r, dem)

            if mp[(num, dem)]:
                return "(" + str(q) + rem
            return str(q) + rem

        return sign + str(q) + "." + longDiv(10 * r, dem)
