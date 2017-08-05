;(function($){
    "use strict";
    $.fn.smartHover = function(options) {
        options = options || {};
        if(!options.hasOwnProperty('background')) {
            console.error("[Smart Hover]: Property 'background' does not exist in options object! ");
            return this;
        }
        if(!options.hasOwnProperty('images')) {
            console.warn("[Smart Hover]: Property 'images' does not exist in options object! ");
            options.images = options.images || [];
        }
        else if(!Array.isArray(options.images)) {
            console.warn("[Smart Hover]: Property 'images' must be an Array! ");
            options.images = (typeof options.images !== "object") ? [options.images] : options.images;
        }
        options.imageClass = options.imageClass || 'SmartHoverDev-images';
        options.exclusive = options.exclusive || false;
        options.onHover = options.onHover || function(){};
        options.onClick = options.onClick || function(){};

        var $this = this;
        var $images = [];
        var persistant = [];
        var $canvases = [];
        var bgWidth = 0;
        var bgHeight = 0;
        var hoveredClass = options.imageClass + "-hovered";
        var clickedClass = options.imageClass + "-clicked";

        var preloader = function(imgs) {
            var promises = [];

            for(var i = 0; i < imgs.length; i++) {
                promises.push(new Promise(function(resolve, reject) {
                    var img = new Image();
                    img.style.display = 'none';
                    img.style.position = 'absolute';
                    img.className = options.imageClass;
                    img.onload = function() {
                        var $img = $(img);
                        $images.push($img);
                        $this.append($img);
                        bgWidth = img.width;
                        bgHeight = img.height;
                        resolve();
                    };
                    img.onerror = reject;
                    img.src = imgs[i];
                }));
            }

            return Promise.all(promises);
        };
        var createBackground = function(background, bgClass) {
            $this.prepend(['<img src="', background ,'" class="', bgClass, '" style="position: absolute">'].join(''));
        };

        var generateCanvas = function(images) {
            var $canvas;
            var context;
            for(var i = 0; i < images.length; i++) {
                $canvas = $(["<canvas width='", bgWidth, "' height='", bgHeight, "' style='display: none;'></canvas>"].join(''));
                context = $canvas[0].getContext('2d');
                context.drawImage($images[i][0], 0, 0);
                $this.append($canvas);
                $canvases.push($canvas);
            }
        };
        var showImage = function(ind) {
            $images[ind].show();
        };
        var hideImage = function(ind) {
            $images[ind].hide();
        };
        var isUnderCursor = function(ind, pos) {
            var canvas = $canvases[ind][0];
            var context = canvas.getContext('2d');
            var pixel = context.getImageData(pos.x, pos.y, 1, 1);
            return pixel.data[3] !== 0;
        };
        var getImagesUnderCursor = function(position) {
            var images = [];
            for(var i = 0; i < $images.length; i++) {
                images.push({
                    ind: i,
                    underCursor: isUnderCursor(i, position),
                    src: $images[i].attr('src')
                });
            }
            return images;
        };
        var moveListener = function(ev) {
            var offset = {
                x: ev.offsetX,
                y: ev.offsetY
            };
            var images = getImagesUnderCursor(offset);
            for(var i = 0; i < images.length; i++) {
                if( images[i].underCursor ) {
                    showImage(images[i].ind);
                    $images[images[i].ind].addClass(hoveredClass);
                    $this.trigger('hoverHovered', {image: images[i].ind, src: images[i].src});
                }
                else {
                    if( persistant.indexOf(images[i].ind) === -1 ) {
                        hideImage(images[i].ind);
                    }
                    $this.trigger('hoverUnhovered', {image: images[i].ind, src: images[i].src});
                    $images[images[i].ind].removeClass(hoveredClass);
                }
            }
        };
        var attachListeners = function() {
            $this.on('mouseenter', function() {
                $this.on('mousemove', moveListener);
            });
            $this.on('mouseleave', function() {
                $this.off('mousemove', moveListener);
                for(var i = 0; i < $images.length; i++) {
                    if( persistant.indexOf(i) === -1 ) {
                        hideImage(i);
                    }
                }
            });
            $this.on('click', function(ev) {
                var offset = {
                    x: ev.offsetX,
                    y: ev.offsetY
                };
                var images = getImagesUnderCursor(offset);
                if( options.exclusive ) {
                    persistant.length = 0;
                }
                for(var i = 0; i < images.length; i++) {
                    if( options.exclusive ) {
                        hideImage(images[i].ind);
                    }
                    if( images[i].underCursor ) {
                        if( persistant.indexOf(images[i].ind) === -1 ) {
                            persistant.push(images[i].ind);
                            showImage(images[i].ind);
                            $images[images[i].ind].addClass(clickedClass);
                            $this.trigger('hoverClicked', {ind: images[i].ind, toggled: true, src: images[i].src});
                        }
                        else {
                            var ind = persistant.indexOf(images[i].ind);
                            persistant.splice(ind, 1);
                            $images[images[i].ind].removeClass(clickedClass);
                            $this.trigger('hoverClicked', {ind: images[i].ind, toggled: false, src: images[i].src});
                        }
                    }
                }
            });
        };

        var run = function() {
            createBackground(options.background, options.imageClass);
            generateCanvas(options.images);
            attachListeners();
            $this.trigger('hoverLoaded');
        };

        preloader(options.images, options.imageClass).then(function() {
            run();
        });

        $this.on('hoverHovered', function(ev, args) {
            options.onHover(args);
        });
        $this.on('hoverClicked', function(ev, args) {
            options.onClick(args);
        });

        return this;
    };
})(jQuery);
