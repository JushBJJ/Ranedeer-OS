<p styles="text-align:center;">Ranedeer</p>
<p styles="text-align:center;">
  Currently in 32 bit support only, you can test it out by using qemu, but I only test Ranedeer using the command "qemu-system-i386 Ranedeer". This OS will start with the sources of www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf then at the end, I will add Ranedeers own features. Feel free to pull requests on support, currently I needs 64 bit support but I guess its really simple but I wan't to focus on the main stuff happening.
  You can compile this by going into the Ranedeer folder and simply type in the command "make". Then it will do the automated tasks and automatically start up qemu for you. Also feel free to make pull requests to organise files but this will require changing up a bit of code, but thats completely fine for me.

  You may notice that I almost comepletely copied and pasted the bootsector code and related (except the kernel and relations), this is because I couldn't get it woking a couple of times when I typed it out, I promise to recode the whole bootsector but I guess its gonna be kinda the same but different function names, sorry about that :(
</p>
